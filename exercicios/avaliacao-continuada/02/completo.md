# Estrutura de Dados Avançado

Rubens Rabêlo Soares

## Questão 01)

### Resposta:

Eu encontrei um pequeno erro no pseudocódigo e corrigi a função para:

```bash
Função F(h)
    se h <= 1 então
        retorne h
    senão
        retorne F(h-1) + F(h-2)
```

Essa função é recursiva e, ao ser executada, gera uma árvore de Fibonacci, onde cada chamada da função corresponde a um nó da árvore.

Seja:

- ( N(h) ) o número de nós da árvore de Fibonacci de altura (h)
- ( C(h) ) o número de chamadas da função (F(h))

Vamos provar, por indução matemática, que:

$$
N(h) = C(h)
$$

#### Casos base

Para (h = 0), a função executa apenas (F(0)):

$$
N(0) = 1
$$

$$
C(0) = 1
$$

Para (h = 1):

$$
N(1) = 1
$$

$$
C(1) = 1
$$

Logo,

$$
N(0) = C(0) \quad \text{e} \quad N(1) = C(1)
$$

#### Passo de indução

Ao calcular (F(h)), ocorre:

- 1 chamada da função atual
- chamadas de (F(h-1))
- chamadas de (F(h-2))

Portanto, o número de chamadas é:

$$
C(h) = 1 + C(h-1) + C(h-2)
$$

Na árvore de Fibonacci ocorre o mesmo:

- 1 nó raiz
- subárvore de altura (h-1)
- subárvore de altura (h-2)

Logo, o número de nós é:

$$
N(h) = 1 + N(h-1) + N(h-2)
$$

#### Hipótese de indução

Suponha que seja verdadeiro para um valor (k):

$$
N(k) = C(k)
$$

e

$$
N(k-1) = C(k-1)
$$

### Provar para (k+1)

Partindo da definição de nós:

$$
N(k+1) = 1 + N(k) + N(k-1)
$$

Substituindo a hipótese de indução:

$$
N(k+1) = 1 + C(k) + C(k-1)
$$

Pela definição de chamadas:

$$
C(k+1) = 1 + C(k) + C(k-1)
$$

Portanto,

$$
N(k+1) = C(k+1)
$$

Portanto, como os casos base são verdadeiros e o passo de indução foi demonstrado, conclui-se que:

$$
N(h) = C(h)
$$

para todo (h > 0), ou seja, o número de nós da árvore de Fibonacci de altura (h) é igual ao número de chamadas da função (F(h)).

---

## Questão 02)

### Respostas

**item a)**

A afirmação é **verdadeira**.

#### Demonstração (Prova Direta)

Pela definição, uma **árvore binária completa** é aquela que apresenta a seguinte propriedade: 

> se \(v\) é um nó tal que alguma subárvore de \(v\) é vazia, então \(v\) se localiza no último ou no penúltimo nível da árvore.

Já uma **árvore AVL** é: 

> uma árvore binária \(T\) tal que, para todo nó \(v\), as alturas de suas duas subárvores, esquerda e direita, diferem em módulo de até uma unidade, ou seja:

$$
|h_D(v) - h_E(v)| \leq 1
$$

Vamos analisar os possíveis casos de um nó \(v\) em uma árvore binária completa.

##### Caso 1: nó acima do penúltimo nível

Se o nó \(v\) não está no último nem no penúltimo nível, então, pela definição de árvore completa, ele não pode ter subárvore vazia.

Logo, ele possui duas subárvores com a mesma altura:

$$
h_E(v) = h_D(v)
$$

Assim,

$$
|h_D(v) - h_E(v)| = |h - h| = 0 \leq 1
$$

##### Caso 2: nó no penúltimo nível

Pela definição de árvore completa, um nó no penúltimo nível pode ter uma subárvore vazia e outra não.

Assim, as alturas possíveis são:

$$
h_E(v) = 1 \quad e \quad h_D(v) = 0
$$

ou

$$
h_E(v) = 0 \quad e \quad h_D(v) = 1
$$

Logo,

$$
|h_D(v) - h_E(v)| = |1 - 0| = 1 \leq 1
$$

##### Caso 3: nó no último nível

O nó não possui subárvores.

$$
h_E(v) = 0
$$

$$
h_D(v) = 0
$$

Então,

$$
|h_D(v) - h_E(v)| = |0 - 0| = 0 \leq 1
$$

Em todos os casos possíveis, a diferença entre as alturas das subárvores esquerda e direita de qualquer nó \(v\) é menor ou igual a 1.

Portanto, a árvore satisfaz a definição de árvore AVL.

$$
|h_D(v) - h_E(v)| \leq 1
$$

Logo, **toda árvore binária completa é também uma árvore AVL**.

---

**item b)**

A afirmação é **verdadeira**.

#### Demonstração (Prova Direta)

Seja \(T\) uma árvore binária cheia.

Pela definição de árvore cheia, temos que:

> se um nó \(v\) possui alguma subárvore vazia, então \(v\) está no último nível da árvore.

Queremos provar diretamente que \(T\) é uma árvore binária completa.

Para isso, devemos verificar a definição de árvore completa, que exige que:

> se um nó \(v\) possui alguma subárvore vazia, então \(v\) está no último ou no penúltimo nível.

Sabemos que, na árvore cheia:

$$
v \in \{\text{último nível}\}
$$

Como todo nó que pertence ao último nível também pertence ao conjunto "último ou penúltimo nível", então:

$$
\{\text{último nível}\} \subseteq \{\text{último nível ou penúltimo nível}\}
$$

Logo,

$$
v \in \{\text{último nível ou penúltimo nível}\}
$$

Assim, a condição exigida pela árvore completa é satisfeita.

Como partimos da definição de árvore cheia e mostramos diretamente que ela satisfaz a definição de árvore completa, concluímos que:

$$
\text{Toda árvore binária cheia é completa}
$$

Logo, a afirmação é **verdadeira**.

---

## Questão 03

### Resposta:

```c++
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
};

// Função auxiliar que retorna a altura
// Se não for AVL, retorna -1
int altura(Node *node) {
    if (node == NULL)
        return 0;

    int h_esq = altura(node->left);
    if (h_esq == -1) return -1;

    int h_dir = altura(node->right);
    if (h_dir == -1) return -1;

    if (abs(h_esq - h_dir) > 1)
        return -1;

    return 1 + max(h_esq, h_dir);
}

bool eh_avl(Node *node) {
    return altura(node) != -1;
}
```

---

## Questão 04

### Resposta:

Para provar que a altura é \(O(\log n)\), vou mostrar que o número mínimo de nós de uma árvore 2-balanceada de altura \(h\) cresce exponencialmente.

Se o número de nós cresce exponencialmente, então a altura cresce logaritmicamente em função de \(n\).


#### Número mínimo de nós

Seja \(N(h)\) o número mínimo de nós de uma árvore 2-balanceada de altura \(h\).

Para obter o menor número de nós possível, a árvore deve estar o mais desbalanceada possível, mas ainda respeitando:

$$
|h_D(v) - h_E(v)| \leq 2
$$

Assim, a pior situação ocorre quando:

- uma subárvore tem altura \(h-1\)
- a outra tem altura \(h-3\)

Logo, o número mínimo de nós satisfaz a recorrência:

$$
N(h) = 1 + N(h-1) + N(h-3)
$$

onde:

- 1 é o nó raiz
- \(N(h-1)\) é a subárvore maior
- \(N(h-3)\) é a subárvore menor


#### Casos base

Para pequenas alturas temos:

$$
N(0) = 1
$$

$$
N(1) = 2
$$

$$
N(2) = 3
$$

#### Crescimento da função

A recorrência é:

$$
N(h) = 1 + N(h-1) + N(h-3)
$$

Podemos escrever:

$$
N(h) \geq N(h-1) + N(h-3)
$$

Essa recorrência cresce de forma exponencial, semelhante à sequência de Fibonacci.

Assim, existe uma constante \(c > 1\) tal que:

$$
N(h) \geq c^h
$$

#### Relação entre altura e número de nós

Sabemos que o número total de nós da árvore é \(n\), então:

$$
n \geq N(h)
$$

Logo:

$$
n \geq c^h
$$

Aplicando logaritmo nos dois lados:

$$
\log n \geq h \log c
$$

Isolando \(h\):

$$
h \leq \frac{\log n}{\log c}
$$

Como \(\log c\) é constante, então:

$$
h = O(\log n)
$$

Logo, o número mínimo de nós de uma árvore 2-balanceada cresce exponencialmente com a altura.

Assim, a altura cresce de forma logarítmica em relação ao número de nós.

Portanto,

$$
h = O(\log n)
$$

Logo, **toda árvore 2-balanceada possui altura da ordem de \(O(\log n)\)**.