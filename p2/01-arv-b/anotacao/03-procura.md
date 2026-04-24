**Anotações:**

- Decisão é feito em $x.n + 1$

## Pseudocódigo
```c++
B-TREE-SEARCH(x, k)
    i = 1

    // Passo 1: Busca Linear dentro do nó atual
    // Avança enquanto a chave buscada for maior que as chaves do nó
    while i <= x.n and k > x.key[i]
        i = i + 1
    
    // Passo 2: Verificamos se achamos a chave exatamente neste nó
    if i <= x.n and k == x.key[i]
        return (x, i)  // Sucesso! Retorna o nó e o índice
    
    // Passo 3: Se não achamos e chegamos na folha, a chave não existe
    elif x.leaf
        return NIL
    
    // Passo 4: Se não é folha, mergulhamos no filho apropriado
    else
        DISK-READ(x.c[i]) // Traz o filho do disco para a RAM
        return B-TREE-SEARCH(x.c[i], k)

```