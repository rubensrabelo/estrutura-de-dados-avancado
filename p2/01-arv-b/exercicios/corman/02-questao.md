**18.1-2** - For what values of $t$ is the tree of *Figure 18.1* a legal B-tree?

**Resposta:**
Para determinar os valores de $t$ para os quais a árvore é válida, devemos analisar os nós com a menor e a maior quantidade de chaves (ignorando a raiz), respeitando as propriedades da Árvore-B:

**1. Pelo limite mínimo de chaves ($t - 1$):**

Observando a imagem, os nós com menos chaves possuem 2 chaves (ex: $\{B, C\}$). Para que a árvore seja legal, o mínimo permitido deve ser menor ou igual a esse valor:

$$
t - 1 \le 2 \implies t \le 3
$$ 

**2. Pelo limite máximo de chaves ($2t - 1$):**

O nó com a maior quantidade de chaves possui 3 chaves (nó $\{Q, T, X\}$). Para que a árvore seja legal, o máximo permitido deve ser maior ou igual a esse valor:

$$
2t - 1 \ge 3 \implies 2t \ge 4 \implies t \ge 2
$$ 

**Conclusão:**
A árvore da Figura 18.1 é uma Árvore-B válida para os valores de $t = 2$ e $t = 3$.