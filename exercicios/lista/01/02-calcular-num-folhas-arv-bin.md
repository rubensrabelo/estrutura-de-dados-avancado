Questão 02) Calcular o número de folhas de uma árvore binária

```c++
int calculateLeaf(Node* node) {
    if(node == nullptr)
        return 0;
    if(node->left == nullptr && node->right == nulptr)
        return 1;
    Node leftNode = calculateLeaf(node->left);
    Node rightNode = calculateLeaf(node->right);
    
    return leftNode + rightNode;
}
```