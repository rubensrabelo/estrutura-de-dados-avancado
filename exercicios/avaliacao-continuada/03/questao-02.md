![Imagem da questão 01](./img/questao-02.png)

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
