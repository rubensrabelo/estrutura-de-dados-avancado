**Questão 05)** nó com maior número em uma árvore binária

```c++
Node* findGreatestNumber(Node *node) {
    if(node == nullptr)
        return nullptr

    Node *rightMax = findGreatestNumber(node->right);
    Node *leftMax = findGreatestNumber(node->left);

    Node *max = node;

    if(leftMax != nullptr && leftMax->key > max->key)
        max = leftMax;

    if(rightMax != nullptr && rightMax->key > max->key)
        max = rightMax;

    return max;
}
```