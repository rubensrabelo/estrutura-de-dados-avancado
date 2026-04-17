Questão 01) Função para calcular o número de nós de uma árvore binária

```c++
int calculateNodes(Node* node) {
    if(node == nullptr)
        return 0;
    int leftNode = calculateNodes(node->left);
    int rightNode = calculateNodes(node->right);

    return 1 + leftNode + rightNode;
}
```