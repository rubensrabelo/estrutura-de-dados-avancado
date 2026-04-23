"
Uma árvore-B T é uma árvore enraizada com T.root possuindo as seguintes propriedades:

1. Atributos do nó x:
   a. $x.n$: quantidade de chaves atualmente armazenadas no nó;
   b. $x.key_1 \le x.key_2 \le \dots \le x.key_{x.n}$: chaves armazenadas em ordem crescente;
   c. $x.leaf$: booleano que indica se o nó é folha (TRUE) ou interno (FALSE).
2. Filhos: Nós internos possuem $x.n + 1$ ponteiros $c_1, c_2, \dots, c_{x.n+1}$ para seus filhos. Folhas não possuem filhos.
3. Separação de chaves: As chaves de $x$ separam os intervalos das subárvores. Se $k_i$ é uma chave na subárvore de $c_i$, então:
$$
k_1 \le x.key_1 \le k_2 \le x.key_2 \dots \le x.key_{x.n} \le k_{x.n+1}
$$ 
4. Balanceamento: Todas as folhas estão no mesmo nível (mesma profundidade).
5. Limites de chaves (Grau mínimo $t \ge 2$):
   a. Mínimo: Todo nó (exceto a raiz) deve ter ao menos $t - 1$ chaves. Nós internos têm ao menos $t$ filhos. Se a árvore não estiver vazia, a raiz deve ter ao menos 1 chave.
   b. Máximo: Cada nó pode ter no máximo $2t - 1$ chaves. Nós internos têm no máximo $2t$ filhos.
