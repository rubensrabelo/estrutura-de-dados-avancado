#include<iostream>

#include "BST.h"

// Contructor
BST::BST()
{
    root = nullptr;
}

// Destrutor
void BST::_destroy(Node *node)
{
    if (node == nullptr)
        return;

    _destroy(node->left);
    _destroy(node->right);
    delete node;
}

BST::~BST()
{
    _destroy(root);
    root = nullptr;
}

// Inserir

Node *BST::_insert(Node *node, int key)
{
    if (node == nullptr)
        return new Node(key, nullptr, nullptr);

    if (node->key > key)
        node->left = _insert(node->left, key);

    if (node->key < key)
        node->right = _insert(node->right, key);

    return node;
}

void BST::insert(int key)
{
    root = _insert(root, key);
}

// Buscar
Node *BST::_search(Node *node, int key)
{
    if (node == nullptr)
        return nullptr;

    if (key == node->key)
        return node;
    else if (key < node->key)
        node = _search(node->left, key);
    else
        node = _search(node->right, key);

    return node;
}

bool BST::search(int key)
{
    if (_search(root, key) == nullptr)
        return false;
    return true;
}

// Remover
Node* BST::_removeRoot(Node* node) {
    Node* parent;
    Node* q;

    if (node->right == nullptr) {
        q = node->left;
    } else {
        parent = node;
        q = node->right;

        while (q->left != nullptr) {
            parent = q;
            q = q->left;
        }

        if (parent != node) {
            parent->left = q->right;
            q->right = node->right;
        }

        q->left = node->left;
    }

    delete node;
    return q;
}

Node *BST::_remove(Node *node, int key)
{
    if (node == nullptr)
        return nullptr;

    if (key == node->key)
        return _removeRoot(node);

    if (key < node->key)
        node->left = _remove(node->left, key);
    else
        node->right = _remove(node->right, key);

    return node;
}

void BST::remove(int key)
{
    root = _remove(root, key);
}


// Exibir
void BST::_show(Node* node, std::string prefix, bool isLeft) {
    if (node == nullptr)
        return;

    std::cout << prefix;

    std::cout << (isLeft ? "├── " : "└── ");
    std::cout << node->key << std::endl;

    _show(node->left, prefix + (isLeft ? "│   " : "    "), true);
    _show(node->right, prefix + (isLeft ? "│   " : "    "), false);
}

void BST::show() {
    if (root == nullptr) {
        std::cout << "Arvore vazia\n";
        return;
    }

    std::cout << root->key << std::endl;
    _show(root->left, "", true);
    _show(root->right, "", false);

    std::cout << "\n";
}