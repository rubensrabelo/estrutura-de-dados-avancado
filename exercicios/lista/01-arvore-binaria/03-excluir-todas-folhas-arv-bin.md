**Questão 03)**

```c++
// Fiz a importação da Struct Node

Node* removeLeaf(Node *node) {
    if(node == nullptr)
        return nullptr

    if(node->left == nullptr && node->rigth == nullptr) {
        delete node;
        return nullptr;
    }

    node->left = removeLeaf(node->left);
    node->right = removeLeaf(node->right);

    return node;
}
```