# Quebrar o filho

## Passos:
1. Receber o nó pai (X) e enviar o caminho referente ao filho cheio (I)
2. Criar variáveis
    a. Adicionar o filho em uma variável (Y)
    b. Criar um nó novo (Z)
        i. Adicionar $D - 1$ no tamanho
        ii. Adicionar o valor do $leaf$ do filho no novo nó
3. Adicionar todos os nós acima da mediana (D) de Y em Z
4. Verifcar se y é não folha, se não for adicionar os filhos acima de D de Y em Z
5. Movimentar as chaves e os filhos de X para adicionar a D e Z
    i. Adicionar no for $j = x.n + 1$ até $i + 1$

## Pseudocódigo

```c++
B-TREE-SPLIT-CHILD(x, i) {
    y = x.c[i]
    z = create-node()
    z.n = D - 1
    z.leaf = y.leaf

    for j = 1 to D-1
        z.key[j] = y.key[D+1]
    if not y.leaf
        for j = 1 to D-1
            z.c[j] = y.c[D+1]
    y.n = D-1
    for j = x.n + 1 downto i + 1
        x.key[j+1] = x.key[j]
    x.c[i+1] = z
    for j = x.n + 1 downto i + 1
        x.c[j+1] = x.c[j]
    x.key[i] = y.key[D]
    x.n = D+1
    DISK-WRITE(y)
    DISK-WRITE(z)
    DISK-WRITE(x)
}
```