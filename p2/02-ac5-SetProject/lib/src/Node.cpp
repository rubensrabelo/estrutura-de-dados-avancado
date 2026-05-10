#include "../include/Node.h"

Node::Node(int key)
{
    this->key = key;

    color = RED;

    left = nullptr;
    right = nullptr;
    parent = nullptr;
}