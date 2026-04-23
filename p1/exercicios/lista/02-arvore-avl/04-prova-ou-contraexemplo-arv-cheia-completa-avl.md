**Questão 04)**

**Item a)** Toda árvore cheia é completa.

Verdade.
Pela definição, uma *árvore cheia* é aquela em que, se *v* é um nó com alguma de suas subárvores vazia, então *v* se localiza no último nível, enquanto uma *árvore completa* é aquela em que, se *v* é um nó tal que alguma subárvores de *v* é vazia, então *v* se localiza ou no último ou no penúltimo nível dá árvore. Logo, se tivermos uma árvore *T* cheia, e se ela possui um nó *v* faltando alguma de suas subárvores, *v* se localiza último nível, o que contempla também a definição de *árvore completa* que *v* estaria ou no penúltimo ou no último nível da árvore.

**Item b)** Toda árvore AVL é completa.

Falso.
Exemplo:

```mermaid
graph
    subgraph Árvore AVL e Não completa
    direction TD
    A((5)) --> B((1))
    A((5\nfb=-1)) --> C((6))
    
    B((1\nfb=1)) --> D((0\nfb=0))
    B((1)) --> E((2))

    E((2\nfb=1)) --> F((4\nfb=0))

    C((6\nfb=1)) --> G((7\nfb=0 ))
    end
```

Pela definição de AVL, essa árvore aprensenta a diferença de altura entre as subárvores esquerda e direito dentro do intervalo de [-1, 0, 1]. Porém, essa árvore não entra na definição de *Árvore Completa*, pois o nós 6 não tem o filho esquerdo e não se localiza no último ou no penúltimo nível, como pedido pela definição.

**Item c)** Toda árvore estritamente binária é AVL

Falso.
Exemplo:
```mermaid
graph
    subgraph Árvore Estritamente Binária e Não AVL
    direction TD
    A((10)) --> B((5))
    A((10\nfb=-2)) --> C((15\nfb=0))

    B((5)) --> D((3))
    B((5\nfb=-1)) --> E((6\nfb=0))

    D((3)) --> F((2\nfb=0))
    D((3\nfb=0)) --> G((4\nfb=0))
    
    end
```

Como podemos observar, a árvore é estritamente binária, o que quer que os seus nós tem 0 ou 2 filhos, mas ela não é AVL, pois a raiz apresentar um fator de balanceamento de -2, indicando que a árvore está desbalanceada a esquerda