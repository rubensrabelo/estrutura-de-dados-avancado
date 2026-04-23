**18.1-1** - Why isn’t a minimum degree of $t = 1$ allowed?

**Resposta:**
Não se permite $t = 1$ porque isso violaria as propriedades fundamentais de existência e busca da Árvore-B. De acordo com a definição, cada nó (exceto a raiz) deve ter pelo menos $t - 1$ chaves. Se $t = 1$, o mínimo seria 0 chaves. Isso permitiria a existência de nós vazios na árvore, o que impossibilitaria o processo de busca, já que não haveria chaves para atuar como separadores entre os ponteiros dos filhos. 
Além disso, com $t = 1$, o número máximo de chaves seria $2t - 1 = 1$. Uma árvore onde cada nó tem no máximo uma chave e pode ter zero chaves deixaria de ser uma estrutura de busca balanceada e eficiente, podendo se degradar em uma estrutura infinita de nós vazios sem nunca disparar uma operação de divisão.