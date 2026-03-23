#ifndef NODE_HPP
#define NODE_HPP

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k, Node* l = nullptr, Node* r = nullptr)
        : key(k), left(l), right(r) {}
};

#endif