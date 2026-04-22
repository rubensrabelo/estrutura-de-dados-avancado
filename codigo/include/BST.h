#ifndef BST_H
#define BST_H

#include "Node.h"

class BST
{
private:
    Node *root;

    void _destroy(Node *node);
    Node *_insert(Node *node, int key);
    Node *_removeRoot(Node *node);
    Node *_remove(Node *node, int key);
    Node *_search(Node *node, int key);
    void _show(Node* node, std::string prefix, bool isLeft);

public:
    BST();
    ~BST();

    void insert(int key);
    void remove(int key);
    bool search(int key);
    void show();
};

#endif