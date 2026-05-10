#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
#include <stdexcept>

#include "Node.h"

class RBTree
{
protected:
    Node *root;

    Node *NIL;

    int treeSize;

    void leftRotate(Node *x);

    void rightRotate(Node *y);

    void insertFix(Node *z);

    void transplant(Node *u, Node *v);

    void eraseFix(Node *x);

    Node *search(Node *node, int key) const;

    Node *minimum(Node *node) const;

    Node *maximum(Node *node) const;

    void clear(Node *node);

    void show(Node *node, int level) const;

public:
    RBTree();

    virtual ~RBTree();

    void insert(int key);

    void erase(int key);

    bool contains(int key) const;

    int getMinimum() const;

    int getMaximum() const;

    int successor(int key) const;

    int predecessor(int key) const;

    void clear();

    bool empty() const;

    int size() const;

    void swap(RBTree &other);

    void Show() const;
};

#endif