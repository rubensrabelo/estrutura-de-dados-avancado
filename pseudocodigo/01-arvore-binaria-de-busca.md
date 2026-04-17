# Árvore Binária de Busca

## Representação do Nó:

```
struct Node {
    int key;
    Node* rigth;
    Node* left;
}
```

## Pseudocódigo de Inserir
- Precisa do ponteiro para a raiz e chave a ser inserida
- ponteiro para raiz da árvore resultante

```
Node* insert(Node* node, key) {
    if node == null then
        return new Node(key, null, null);
    end if

    if key < node->key then
        node->left = insert(node->left, key);
    end if

    else if key > node->key then
        node->rigth = inser(node->right, key);
    end if

    return Node;
}
```

## Pseudocódigo de Buscar

```
Node* seach(Node* node, int key) {
    if node == null then
        return null;
    end if

    if key == node.key then
        return key;
    end if

    if key < node->key then
        search(node->left, key);
    end if

    if key > node->key
        search(node->right, key);
    end if
}
```

## Pseudocódigo de Remover

```
Node * remove(Node *node, key) {
    if node == null then
        return null;
    end if

    if key == node->key then
        return removeRoot(node);
    end if

    if key < node->key then
        node->left = remove(node->left, key);
    end if

    if key > node->key then
        node->tight = remove(node->right, key);
    end if

    return node;
}

// Se não tiver filho direito - esquerdo assume a raiz
// Se tiver filho direito - sucessor da raiz

Node* removeRoot(Node* node) {
    Node *father, *q;

    if node->right == null then
        q = node->left;
    end if
    else
        father = node;
        q = node->right;

        while q->left != null then
            father = q;
            q = q->left;
        end while

        if father != node then
            father->left = q->right;
            q->right = node->right;
        end if
        q->left = node->left;
    end else
    delete node;
    return q;
}
```
