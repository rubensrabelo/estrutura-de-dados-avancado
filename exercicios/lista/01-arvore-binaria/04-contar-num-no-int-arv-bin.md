**Questão 04)**

```c++
// Importei a struct Node

int calculateTotalNode(Node* node) {
    if(node == nullptr)
        return 0;

    if(node->left == nullptr && node->right == nullptr)
        return 0;

    int totalLeft = calculateTotalNode(node->left);
    int totalRight = calculateTotalNode(node->right);

    return 1 + totalLeft + totalRight;
}
```