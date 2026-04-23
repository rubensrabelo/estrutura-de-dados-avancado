# Percursos em Árvores Binárias
- realizo a importação do Node

## Pseudocódigo da Pré-ordem
- Raiz, esquerda e direita

```
// Recursivo
void preorder(Node* ptr) {
    if ptr != NULL then
        visit(ptr)
        preorder(ptr->left)
        preorder(ptr->right)
    end if
}

// Iterativo
void preorder(Node* root) {
    Stack s

    if root != NULL the
        s.push(root)
    end if

    while p != NULL do
        Node* node = s.top()
        s.pop()
        visit(node)

        if node->left != NULL then
            s.push(node->left)
        end if

        if node->right != NULL then
            s.push(node->right)
        end if
    end while
}
```

## Pseudocódigo da Pós-ordem
- esquerda, direita e raiz

```
// Recursivo
void post-order(Node* ptr) {
    if ptr != NULL then
        posorder(ptr->left)
        posorder(ptr->right)
        visit(ptr)
    end if
}

// Iterativo
void post-order(Node* root) {
    Stack p1, p2
    
    if root != NULL the
        p1.push(root)
    end if

    while p1 = NULL do
        node = p1.top()
        p1.pop()
        p2.push(node)

        if node->left != NULL then
            p1.push(node->left)
        end if

        if node->right != NULL then
            p1.push(node->right)
        end if
    end while

    while p2 = NULL do
        node = p2.top()
        p2.pop()
        visit(node)
    end while
}
```

## Pseudocódigo da Simétrica
- esquerda, raiz e direita 

```
// Recursivo
void inorder(Node* ptr) {
    if ptr != NULL then
        inorder(ptr->left)
        visit(ptr)
        inorder(ptr->right)
    end if
}

// Iterativo
void inorder(Node* root) {
    Stack s
    node = root

    while p != NULL or node != null do
        if node != NULL
            s.push(node)
            node = node->left
        else
            node = s.top()
            p.pop()
            visit(node)
            node = node->right
        end if
    end while
}
```

## Pseudocódigo Percurso em Largura

```
void levelTraversal(Node* node) {
    Queue q
    q.push(root)

    while q != NULL do
        node = q.front()
        q.pop()
        if node != NULL then
            visit(node)
            q.push(node->left)
            q.push(node->right)
        end if
    end while
}
```