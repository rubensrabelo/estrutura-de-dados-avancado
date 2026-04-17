**Questão 01)** Em uma árvore AVL, a ordem de inserção dos elementos não importa pois sempre
resulta na mesma árvore. Prove ou mostre um contra exemplo.

**Resposta:**

**Falso.**

**Exemplo:** seja *T* uma árvore AVL de altura *h*, cuja subárvore esquerda $T_E$ tem altura *h - 1* e cuja subárvore direita $T_D$ tem altura *h - 2*. Nesse caso, o fator de balanceamento da raiz de *T* é:

$$
bf = (h - 2) - (h - 1) = -2 + 1 = -1
$$

(ou, equivalentemente, $1$, dependendo de qual lado é maior).

Ao inserir um novo valor na subárvore de maior altura (por exemplo, em $T_E$), pode ocorrer aumento da altura de $T_E$ para *h*. Assim, a árvore *T* passa a ter altura *h + 1*, com:

$$
bf = (h - 2) - h = -2
$$

(ou $2$, se a subárvore direita for a maior).

Como o fator de balanceamento sai do intervalo $[-1, 0, 1]$, a árvore fica desbalanceada, exigindo uma rotação para restaurar a condição AVL.

Isso mostra que a inserção de um mesmo valor em uma parte específica da árvore pode alterar a estrutura final (por provocar rotações), o que prova que a ordem de inserção importa e que a afirmação é falsa.
