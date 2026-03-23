#ifndef bst_hpp
#define bst_hpp

#include <iostream>
#include <string>

#include "Node.hpp"

class BST
{
public:
    BST()
    {
        m_root = nullptr;
    }

    ~BST()
    {
        m_root = clear(m_root);
    }

    void insert(int v) {
        m_root = _insert(m_root, v);
    }

    void clear()
    {
        m_root = clear(m_root);
    }

    void show() {
        bshow(m_root, "");
    }

    bool contains(int k) const {
        Node *aux = contains(m_root, k);
        return aux != nullptr;
    }

    bool contains_iterative(int k) const {
        Node* current_node = m_root;
        while (current_node != nullptr)
        {
            if(current_node->key == k)
                return true;

            if(current_node->key == k)
                current_node = current_node->left;
            else
                current_node = current_node->right;
        }

        return false;
    }

    void remove(int k) {
        m_root = _remove(m_root, k);
    }

    int height() const {
        return _height(m_root);
    }

    int size() const {
        return _size(m_root);
    }

private:
    Node *m_root;

    Node *_insert(Node *node, int k)
    {
        if (node == nullptr)
        {
            return new Node(k);
        }
        else if (k < node->key)
        {
            node->left = _insert(node->left, k);
        }
        else if (k > node->key)
        {
            node->right = _insert(node->right, k);
        }

        return node;
    }

    Node *clear(Node *node)
    {
        if (node != nullptr)
        {
            node->left = clear(node->left);
            node->right = clear(node->right);
            delete node;
        }

        return nullptr;
    }

    void _clear(Node *node)
    {
        if (node != nullptr)
        {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    void bshow(Node *node, std::string heir) const
    {
        if (node != nullptr && (node->left != nullptr || node->right != nullptr))
        {
            bshow(node->right, heir + "r");
        }

        for (int i = 0; i < (int)heir.size() - 1; i++)
        {
            std::cout << (heir[i] != heir[i + 1] ? "│   " : "    ");
        }

        if (heir != "")
            std::cout << (heir.back() == 'r' ? "┌───" : "└───");
        if (node == nullptr)
        {
            std::cout << "#" << std::endl;
            return;
        }
        std::cout << node->key << std::endl;
        if (node != nullptr && (node->left != nullptr || node->right != nullptr))
            bshow(node->left, heir + "l");
    }

    Node *contains(Node *node, int k) const
    {
        if (node == nullptr || node->key == k)
            return node;

        if (k < node->key)
            return contains(node->left, k);
        else
            return contains(node->right, k);
    }

    Node *_remove(Node *node, int k)
    {
        if (node == nullptr)
            return nullptr;
        if (k == node->key)
            return _remove_node(node->left);
        if (k < node->key)
            return _remove(node->left, k);
        else
            return _remove(node->right, k);
        return node;
    }

    Node *_remove_node(Node *node)
    {
        Node *parent, *q;

        if (node->right == nullptr)
        {
            q = node->left;
        }
        else
        {
            while (q->left != nullptr)
            {
                parent = q;
                q = q->left;
            }
            if(parent != node) {
                parent->left = q->right;
                q->right = node->right;
            }
            q->left = node->left;
        }

        delete node;
        return q;
    }

    int _height(Node* node) const {
        if(node == nullptr)
            return 0;
        
        int left = _height(node->left);
        int right = _height(node->right);
        return 1 + (left > right ? left : right);
    }

    int _size(Node *node) const {
        if(node == nullptr)
            return 0;
        return 1 + _size(node->left) + _size(node->right);
    }
};

#endif