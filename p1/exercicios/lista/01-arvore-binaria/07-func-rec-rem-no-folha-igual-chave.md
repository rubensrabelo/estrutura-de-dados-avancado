**Questão 07)**

```c++
Node* removeNode(Node *node, int key) {
    if(node == nullptr)
        return nullptr;

    if(
        node->key == key &&
        node->left == nullptr &&
        node->right == nullptr
    ) {
        delete node;
        return nullptr;
    }

    node->left = removeNode(node->left, key);
    node->right = removeNode(node->right, key);

    return node;
}
```