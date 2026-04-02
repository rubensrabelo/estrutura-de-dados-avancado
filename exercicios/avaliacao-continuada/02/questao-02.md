![Imagem da questão 01](./img/questao-02.png)

### Respostas

**item a)**

A afirmação é **verdadeira**.

Pela definição, uma **árvore binária completa** é aquela que apresenta a seguinte propriedade: se (v) é um nó tal que alguma subárvore de (v) é vazia, então (v) se localiza no último ou no penúltimo nível da árvore.

Já uma **árvore AVL** é uma árvore binária (T) tal que, para todo nó (v), as alturas de suas duas subárvores, esquerda e direita, diferem em módulo de até uma unidade, ou seja:

$$
|h_D(v) - h_E(v)| \leq 1
$$

Vamos analisar os possíveis casos de um nó (v) em uma árvore binária completa.

#### Caso 1: nó acima do penúltimo nível

Se o nó (v) não está no último nem no penúltimo nível, então, pela definição de árvore completa, ele não pode ter subárvore vazia.

Logo, ele possui duas subárvores com a mesma altura:

$$
h_E(v) = h_D(v)
$$

Assim,

$$
|h_D(v) - h_E(v)| = |h - h| = 0 \leq 1
$$

#### Caso 2: nó no penúltimo nível

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

#### Caso 3: nó no último nível

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

#### Conclusão

Em todos os casos possíveis, a diferença entre as alturas das subárvores esquerda e direita de qualquer nó (v) é menor ou igual a 1.

Portanto, a árvore satisfaz a definição de árvore AVL.

$$
|h_D(v) - h_E(v)| \leq 1
$$

Logo, **toda árvore binária completa é também uma árvore AVL**.


**item b)**

![Imagem da questão 02](./img/questao-02.png)

### Resposta:

A afirmação é **verdadeira**.

Pela definição, uma **árvore binária cheia** é aquela em que, se (v) é um nó com alguma de suas subárvores vazias, então (v) se localiza no último nível da árvore.

Já uma **árvore binária completa** é aquela que apresenta a seguinte propriedade: se (v) é um nó tal que alguma subárvore de (v) é vazia, então (v) se localiza no último ou no penúltimo nível da árvore.

Vamos analisar as duas definições.

Na árvore cheia, sempre que um nó possui alguma subárvore vazia, ele obrigatoriamente está no último nível.

Ou seja, se existir um nó (v) com subárvore vazia, então:

$$
v \in {\text{último nível}}
$$

Na árvore completa, precisamos que o nó com subárvore vazia esteja no conjunto:

$$
v \in {\text{último nível ou penúltimo nível}}
$$

Observe que todo nó que está no último nível também pertence ao conjunto "último ou penúltimo nível". Logo, a condição da árvore cheia já satisfaz automaticamente a condição da árvore completa.

Podemos representar isso como:

$$
{\text{último nível}} \subseteq {\text{último nível ou penúltimo nível}}
$$

#### Conclusão

Como toda árvore cheia garante que nós com subárvores vazias estejam apenas no último nível, então ela satisfaz a propriedade exigida pela árvore completa.

Portanto,

$$
\text{Toda árvore binária cheia é completa}
$$

Logo, a afirmação é **verdadeira**.
