# Buscar

## Passos:
1. Receber um Nó (X) e um valor alvo (K)
2. Realizar uma busca linear sobre o Nó atual
    a. $i \le X.n$
    b. $K > X.k[i]$
3. Realizar as comparações:
    a. Se $i \le X.n$ e $K == X.k[i]$, então retorna X e i
    b. Se X é uma folha, então retorna NIL
    c. Senão vai até o HD e ler o $X.c[i]$, e chama novamente a função, passando o novo Nó e o K

## Pseudocódigo

```c++
SEARCH-B-TREE(X, K) {
    int i = 1;
    while (i <= X.n && K > X.k[i])
        i++;
    
    if (i <= X.n && K == X.k[i])
        return (X, i)
    if X.leaf
        return NIL
    else {
        DISK-READ(X.c[i])
        return SEARCH-B-TREE(X.c[i], K)
    }
}
```