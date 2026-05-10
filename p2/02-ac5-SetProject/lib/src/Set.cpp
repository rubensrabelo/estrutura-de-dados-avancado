#include "../include/Set.h"

void Set::inorder(Node* node, Set& result) const
{
    if (node == NIL)
        return;

    inorder(node->left, result);

    result.Insert(node->key);

    inorder(node->right, result);
}

void Set::intersectionHelper(Node* node, const Set& R, Set& result) const
{
    if (node == NIL)
        return;

    intersectionHelper(node->left, R, result);

    if (R.contains(node->key))
        result.Insert(node->key);

    intersectionHelper(node->right, R, result);
}

void Set::differenceHelper(Node* node, const Set& R, Set& result) const
{
    if (node == NIL)
        return;

    differenceHelper(node->left, R, result);

    if (!R.contains(node->key))
        result.Insert(node->key);

    differenceHelper(node->right, R, result);
}

void Set::Insert(int x)
{
    insert(x);
}

void Set::Erase(int x)
{
    erase(x);
}

bool Set::Contains(int x)
{
    return contains(x);
}

int Set::Minimum()
{
    return getMinimum();
}

int Set::Maximum()
{
    return getMaximum();
}

int Set::Successor(int x)
{
    return successor(x);
}

int Set::Predecessor(int x)
{
    return predecessor(x);
}

Set Set::Union(const Set& R) const
{
    Set result;

    inorder(root, result);

    R.inorder(R.root, result);

    return result;
}

Set Set::Intersection(const Set& R) const
{
    Set result;

    intersectionHelper(root, R, result);

    return result;
}

Set Set::Difference(const Set& R) const
{
    Set result;

    differenceHelper(root, R, result);

    return result;
}

bool Set::Empty()
{
    return empty();
}

int Set::Size()
{
    return size();
}

void Set::Clear()
{
    clear();
}

void Set::Swap(Set& other)
{
    swap(other);
}