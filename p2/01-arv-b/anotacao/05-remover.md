**Anotações:**

O segredo da remoção na Árvore B é a prevenção. Em vez de apagar a chave e depois consertar a árvore (o que te obrigaria a subir de volta), o algoritmo garante que cada nó onde você pisa já tenha chaves extras. Assim, se você precisar remover algo, o nó nunca ficará "vazio" demais (abaixo do mínimo $t-1$).
Aqui estão os casos detalhados de forma simples:

## O Objetivo: A Passagem Única
O algoritmo quer descer do topo (raiz) até a base (folhas) uma única vez. Para isso, a regra de ouro é: Todo nó que visitamos deve ter pelo menos $t$ chaves (uma a mais que o mínimo obrigatório). Se não tiver, nós "abastecemos" ele antes de entrar.

## Caso 1: A chave está em uma Folha
Se você chegou em uma folha e a chave $k$ está lá, é só apagar. Como garantimos que o nó tinha pelo menos $t$ chaves antes de chegar, ele continuará com pelo menos $t-1$ após a remoção. Tudo certo.

## Caso 2: A chave está em um Nó Interno (Meio da árvore)
Aqui você não pode simplesmente apagar, ou deixaria um "buraco" nos ponteiros. Você tem 3 opções:

* **2a (Vizinho da esquerda rico):** Se o filho à esquerda da chave tiver pelo menos $t$ chaves, você pega a "maior chave" desse filho (o predecessor), sobe ela para o lugar da que você quer apagar e pronto.
* **2b (Vizinho da direita rico):** Se o da esquerda for pobre, mas o da direita tiver pelo menos $t$ chaves, você pega a "menor chave" dele (o sucessor) e coloca no lugar da apagada.
* **2c (Ambos pobres):** Se os dois filhos vizinhos tiverem apenas $t-1$ chaves, você funde os dois filhos em um só nó e coloca a chave que você queria apagar no meio deles. Depois, você desce para esse novo nó e apaga a chave de lá (agora ele é grande o suficiente).

## Caso 3: A chave NÃO está no nó atual (Caminho de descida)
Você está apenas passando por um nó para chegar mais em baixo. Se o próximo nó onde você precisa entrar for "pobre" (tiver apenas $t-1$ chaves), você precisa ajudá-lo antes de entrar:

* **3a (Pedir emprestado):** Se o nó vizinho (irmão) dele for rico, você faz uma rotação: desce uma chave do pai para o nó pobre e sobe uma chave do irmão rico para o pai. O nó agora tem $t$ chaves e você pode entrar.
* **3b (Fusão):** Se o nó e todos os seus irmãos forem pobres, você funde o nó com um irmão e desce uma chave do pai para ser o meio dessa fusão. Se o pai era a raiz e ficou vazio, a árvore diminui de altura (o novo nó fundido vira a nova raiz).
