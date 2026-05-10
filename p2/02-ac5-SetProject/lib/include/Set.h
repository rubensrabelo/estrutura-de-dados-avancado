#ifndef SET_H
#define SET_H

#include "RBTree.h"

class Set : public RBTree
{
private:
    void inorder(Node* node, Set& result) const;

    void intersectionHelper(Node* node, const Set& R, Set& result) const;

    void differenceHelper(Node* node, const Set& R, Set& result) const;

public:
    void Insert(int x);

    void Erase(int x);

    bool Contains(int x);

    int Minimum();

    int Maximum();

    int Successor(int x);

    int Predecessor(int x);

    Set Union(const Set& R) const;

    Set Intersection(const Set& R) const;

    Set Difference(const Set& R) const;

    bool Empty();

    int Size();

    void Clear();

    void Swap(Set& other);
};

#endif