Aqui está a versão ajustada, mantendo o estilo que você queria, mas com a notação matemática correta e mais consistente em Markdown:

---

## Questão 06)

### Resposta

#### Número máximo de nós

O número máximo de nós ocorre quando a árvore é **cheia**, ou seja, quando a diferença de altura entre as subárvores esquerda e direita, em todos os nós, é zero.

Nesse caso, a quantidade de nós no nível ( i ) é ( 2^i ):

```
nível 0: 2^0  (raiz)
nível 1: 2^1
nível 2: 2^2
...
nível h: 2^h
```

O número total de nós ( N_{\text{max}} ) até a altura ( h ) é dado pelo somatório da progressão geométrica:

$$
N_{\text{max}}(h) = \sum_{i=0}^{h} 2^i = 2^{h+1} - 1
$$

---

#### Número mínimo de nós

O número mínimo de nós ocorre quando a árvore é a mais esparsa possível, mantendo a propriedade AVL. Isso acontece quando cada nó possui fator de balanceamento igual a ( 1 ) ou ( -1 ).

Para minimizar os nós em uma árvore de altura ( h ), sua estrutura deve ser composta por:

* uma subárvore com altura ( h - 1 )
* outra subárvore com altura ( h - 2 )

Definindo ( N(h) ) como o número mínimo de nós para uma árvore de altura ( h ), temos a seguinte relação de recorrência:

$$
N(h) = N(h - 1) + N(h - 2) + 1
$$

onde:

* ( N(h - 1) ) e ( N(h - 2) ) representam as subárvores
* o termo ( +1 ) contabiliza a raiz

**Casos base:**

* ( N(0) = 1 ) (árvore com apenas a raiz)
* ( N(1) = 2 ) (raiz e um filho)

---
