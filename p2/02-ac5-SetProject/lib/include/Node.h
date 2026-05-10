#ifndef NODE_H
#define NODE_H

enum Color
{
    RED,
    BLACK
};

struct Node
{
    int key;
    Color color;

    Node *left;
    Node *right;
    Node *parent;

    Node(int key);
};

#endif