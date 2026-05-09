# Inserir

## Passos:

## Pseudocódigo:

```c++
B-TREE-INSERT(T, k) {
    r = T.root

    if r.n == 2D - 1
        s = ALLOCATE-NODE()
        s.leaf = FALSE
        s.n = 0
        s.c[1] = r
        T.root = s
        B-TREE-SPLIT-CHILD(s, 1)
        B-TREE-INSERT-NONFULL(s, k)
    else
        B-TREE-INSERT-NONFULL(r, k)
}

B-TREE-INSERT-NONFULL(x, k) {
    i = x.n
    if x.leaf
        while i >= 1 AND k < x.key[i]
            x.key[i + 1] = x.key[i]
            i = i - 1
        x.key[i + 1] = k
        x.n = x.n + 1
        DISK-WRITE(x)
    else
        while i >= 1 AND k < x.key[i]
            i = i - 1
        i = i + 1
        DISK-READ(x.c[i])
        if x.c[i].n == 2D - 1
            B-TREE-SPLIT-CHILD(x, i)
            if k > x.key[i]
                i = i + 1
        B-TREE-INSERT-NONFULL(x. c[i], k)        
}
```