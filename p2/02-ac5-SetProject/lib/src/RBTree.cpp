#include "../include/RBTree.h"

RBTree::RBTree()
{
    NIL = new Node(0);

    NIL->color = BLACK;
    NIL->left = NIL;
    NIL->right = NIL;
    NIL->parent = NIL;

    root = NIL;

    treeSize = 0;
}

RBTree::~RBTree()
{
    clear();

    delete NIL;
}

void RBTree::leftRotate(Node *x)
{
    Node *y = x->right;

    x->right = y->left;

    if (y->left != NIL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NIL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;

    x->parent = y;
}

void RBTree::rightRotate(Node *y)
{
    Node *x = y->left;

    y->left = x->right;

    if (x->right != NIL)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == NIL)
        root = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;

    x->right = y;

    y->parent = x;
}

void RBTree::insert(int key)
{
    Node *z = new Node(key);

    Node *y = NIL;
    Node *x = root;

    while (x != NIL)
    {
        y = x;

        if (key < x->key)
            x = x->left;
        else if (key > x->key)
            x = x->right;
        else
        {
            delete z;
            return;
        }
    }

    z->parent = y;

    if (y == NIL)
        root = z;
    else if (key < y->key)
        y->left = z;
    else
        y->right = z;

    z->left = NIL;
    z->right = NIL;
    z->color = RED;

    insertFix(z);

    treeSize++;
}

void RBTree::insertFix(Node *z)
{
    while (z->parent->color == RED)
    {
        if (z->parent == z->parent->parent->left)
        {
            Node *y = z->parent->parent->right;

            if (y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;

                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;

                    leftRotate(z);
                }

                z->parent->color = BLACK;
                z->parent->parent->color = RED;

                rightRotate(z->parent->parent);
            }
        }
        else
        {
            Node *y = z->parent->parent->left;

            if (y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;

                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;

                    rightRotate(z);
                }

                z->parent->color = BLACK;
                z->parent->parent->color = RED;

                leftRotate(z->parent->parent);
            }
        }
    }

    root->color = BLACK;
}

Node *RBTree::search(Node *node, int key) const
{
    while (node != NIL && key != node->key)
    {
        if (key < node->key)
            node = node->left;
        else
            node = node->right;
    }

    return node;
}

bool RBTree::contains(int key) const
{
    return search(root, key) != NIL;
}

Node *RBTree::minimum(Node *node) const
{
    while (node->left != NIL)
        node = node->left;

    return node;
}

Node *RBTree::maximum(Node *node) const
{
    while (node->right != NIL)
        node = node->right;

    return node;
}

int RBTree::getMinimum() const
{
    if (root == NIL)
        throw std::runtime_error("Set vazio");

    return minimum(root)->key;
}

int RBTree::getMaximum() const
{
    if (root == NIL)
        throw std::runtime_error("Set vazio");

    return maximum(root)->key;
}

void RBTree::transplant(Node *u, Node *v)
{
    if (u->parent == NIL)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;

    v->parent = u->parent;
}

void RBTree::erase(int key)
{
    Node *z = search(root, key);

    if (z == NIL)
        return;

    Node *y = z;
    Node *x;

    Color originalColor = y->color;

    if (z->left == NIL)
    {
        x = z->right;

        transplant(z, z->right);
    }
    else if (z->right == NIL)
    {
        x = z->left;

        transplant(z, z->left);
    }
    else
    {
        y = minimum(z->right);

        originalColor = y->color;

        x = y->right;

        if (y->parent == z)
        {
            x->parent = y;
        }
        else
        {
            transplant(y, y->right);

            y->right = z->right;
            y->right->parent = y;
        }

        transplant(z, y);

        y->left = z->left;
        y->left->parent = y;

        y->color = z->color;
    }

    delete z;

    if (originalColor == BLACK)
        eraseFix(x);

    treeSize--;
}

void RBTree::eraseFix(Node *x)
{
    while (x != root && x->color == BLACK)
    {
        if (x == x->parent->left)
        {
            Node *w = x->parent->right;

            if (w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;

                leftRotate(x->parent);

                w = x->parent->right;
            }

            if (w->left->color == BLACK &&
                w->right->color == BLACK)
            {
                w->color = RED;

                x = x->parent;
            }
            else
            {
                if (w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;

                    rightRotate(w);

                    w = x->parent->right;
                }

                w->color = x->parent->color;

                x->parent->color = BLACK;
                w->right->color = BLACK;

                leftRotate(x->parent);

                x = root;
            }
        }
        else
        {
            Node *w = x->parent->left;

            if (w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;

                rightRotate(x->parent);

                w = x->parent->left;
            }

            if (w->right->color == BLACK &&
                w->left->color == BLACK)
            {
                w->color = RED;

                x = x->parent;
            }
            else
            {
                if (w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;

                    leftRotate(w);

                    w = x->parent->left;
                }

                w->color = x->parent->color;

                x->parent->color = BLACK;
                w->left->color = BLACK;

                rightRotate(x->parent);

                x = root;
            }
        }
    }

    x->color = BLACK;
}

int RBTree::successor(int key) const
{
    Node *x = search(root, key);

    if (x == NIL)
        throw std::runtime_error("Elemento nao encontrado");

    if (x->right != NIL)
        return minimum(x->right)->key;

    Node *y = x->parent;

    while (y != NIL && x == y->right)
    {
        x = y;
        y = y->parent;
    }

    if (y == NIL)
        throw std::runtime_error("Nao existe sucessor");

    return y->key;
}

int RBTree::predecessor(int key) const
{
    Node *x = search(root, key);

    if (x == NIL)
        throw std::runtime_error("Elemento nao encontrado");

    if (x->left != NIL)
        return maximum(x->left)->key;

    Node *y = x->parent;

    while (y != NIL && x == y->left)
    {
        x = y;
        y = y->parent;
    }

    if (y == NIL)
        throw std::runtime_error("Nao existe predecessor");

    return y->key;
}

void RBTree::clear()
{
    clear(root);

    root = NIL;

    treeSize = 0;
}

void RBTree::clear(Node *node)
{
    if (node != NIL)
    {
        clear(node->left);

        clear(node->right);

        delete node;
    }
}

bool RBTree::empty() const
{
    return root == NIL;
}

int RBTree::size() const
{
    return treeSize;
}

void RBTree::swap(RBTree &other)
{
    std::swap(root, other.root);

    std::swap(NIL, other.NIL);

    std::swap(treeSize, other.treeSize);
}

void RBTree::show(Node *node, int level) const
{
    if (node == NIL)
        return;

    show(node->right, level + 1);

    for (int i = 0; i < level; i++)
        std::cout << "    ";

    std::cout << node->key;

    if (node->color == RED)
        std::cout << "(R)";
    else
        std::cout << "(B)";

    std::cout << std::endl;

    show(node->left, level + 1);
}

void RBTree::Show() const
{
    if (root == NIL)
    {
        std::cout << "Arvore vazia" << std::endl;

        return;
    }

    show(root, 0);
}