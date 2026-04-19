**Questão 2)** Qual o melhor e o pior caso de altura de uma árvore binária de busca e uma árvore AVL para um mesmo número n de elementos?

**Resposta:**

Em uma **árvore binária de busca (BST)**:

- **Melhor caso:** $h \approx \log_2 n$  
  (árvore perfeitamente balanceada, próxima de uma árvore completa)

- **Pior caso:** $h = n - 1 \approx n$  
  (árvore degenerada, semelhante a uma lista encadeada)

Em uma **árvore AVL**:

- **Melhor caso:** $h \approx \log_2 n$  
  (árvore completa ou quase completa)

- **Pior caso:** $h \in O(\log n)$, com valor máximo aproximadamente  
  $1{,}44 \cdot \log_2 n$, devido à condição de balanceamento

Em termos de complexidade, dizemos que, para uma árvore AVL, a altura é sempre   $O(\log n)$, independentemente da ordem de inserção, pois a árvore mantém o balanceamento após cada inserção ou remoção.  

Isso garante que, mesmo no pior caso, a altura permanece logarítmica em relação ao número de elementos.