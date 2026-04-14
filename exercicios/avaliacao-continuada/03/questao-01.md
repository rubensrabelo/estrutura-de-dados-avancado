![Imagem da questão 01](./img/questao-01.png)

### Resposta:

A família de árvores escolhida foi "A árvore AVL Fibonachi"

#### Defição formal:
A árvore AVL de Fibonacci \(F_h\) de altura \(h\) é a árvore binária de busca AVL com o mínimo número de nós \(N(h)\) possível para essa altura, definida recursivamente como segue:

\[
\begin{cases}
N(0) = 1 \\
N(1) = 2 \\
N(h) = 1 + N(h-1) + N(h-2), & h \geq 2
\end{cases}
\]

Sua estrutura consiste em uma raiz com subárvore esquerda \(F_{h-1}\) (altura \(h-1\)) e subárvore direita \(F_{h-2}\) (altura \(h-2\)), satisfazendo o fator de balanceamento |FB| ≤ 1 em todos os nós. Essa recorrência coincide com a sequência de Fibonacci deslocada, onde \(N(h) = F_{h+2}\) (\(F_0 = 0\), \(F_1 = 1\)).

#### Nó a ser removido:
Em cada $T_k$, removo a folha mais à direita da subárvore direita ($T_{k-2}$).

##### Argumento:
A raiz de $T_k$ tem $bf = -1$ porque o lado esquerdo é 1 nível mais alto que o direito. Quando removo a folha do lado direito, esse lado fica ainda menor, então o $bf$ da raiz vai de $-1$ para $-2$, quebrando o invariante AVL e forçando uma rotação.

Após a rotação, a altura da subárvore da raiz diminui em 1. O nó acima da raiz, que também tinha $|bf| = 1$ (sem nenhuma folga), agora vê sua subárvore encolher e também quebra o invariante — mais uma rotação. Isso se repete em cada nível até o topo.

Isso acontece porque nenhum nó da árvore tem $bf = 0$, ou seja, não existe folga em lugar nenhum. Qualquer redução de altura em uma subárvore imediatamente desbalanceia o nó pai.

Como a árvore tem altura $\mathcal{O}(\log n)$ e ocorre uma rotação por nível, o total de rotações é $\mathcal{O}(\log n)$.
