**18.1-3** - Show all legal B-trees of minimum degree 2 that store the keys 1; 2; 3; 4; 5.

**Resposta**:

**Limitações:**

$$
t = 2
t_{min} = t - 1 \implies t_{min} = 1 \\
t_{max} = 2t - 1 \implies t_{max} = 3
$$

Ainda, temos que lembrar que $x.n + 1$ é a quantidade de filhos

Logo, temos

com $h = 1$

**Raiz com 1 nó (2 filhos):**

**caso: a**
Raiz: $\{2\}$
Filhos: $\{1\}$, $\{2, 3, 4\}$

**caso: b**
Raiz: $\{3\}$
Filhos: $\{1, 2\}$, $\{3, 4\}$

**caso: 3**
Raiz: $\{4\}$
Filhos: $\{1, 2, 3\}$, $\{5\}$


**Raiz com 2 nós (3 filhos):**

Raiz: $\{2, 4\}$
Filhos: $\{1\}$, $\{3\}$ e $\{4\}$

Não tem $h = 0$ pois ultrapassaria o $t_{max}$
Não tem $h = 0$ pois um dos filhos seria vazio
