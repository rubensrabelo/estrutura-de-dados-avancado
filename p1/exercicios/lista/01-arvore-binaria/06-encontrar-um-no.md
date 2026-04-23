**Questão 06)**

```c++
Node* findNode(Node* node, int key) {
    if(node == nullptr)
        return nullptr;
    
    if(node->key == key)
        return node;

    Node* leftResut = findNode(node->left, key);

    if(leftResult != null) 
        return leftResult;

    Node* rightResult = findNode(node->right, key);

    return rightResult;
}
```