> **Teorema 2**
> Dada uma árvore binária completa com altura h, seu número mínimo de nós é $2^h$ e seu número máximo de nós é $2^{h+1} − 1$.

fazendo o número total de nós (N) de uma árvore T, o total dos seus nós é N(T)

**Mínimo de nós:**
Para uma árvore binária completa possuir o seu mínimo, ela deve possui o níveis de 0 e h-1, e apenas mais um k mínimo nó para ela ficar com os nós sem filhos no penúltimo e último nível.

logo,
```
Nível 0 --> 2⁰
Nível 1 --> 2¹
Nível 2 --> 2²
...
Nível h-1 --> 2^h-1
```

então, contamos k = 1, para deixar o o nós do nível com 1

$$
N(T) = \sum_{i=0}^{h-1} 2^i + 1 \\
N(T) = (2^{h} - 1) + 1 \\
N(T) = 2^h
$$


**Máximo de nós:**

Já para uma árvore binária completar possui o seu número máximo de nós, ela deve ser uma árvore cheia, pois os nós que não possuem alguma das subárvores estão no último nível, o que continua dentro da definição da árvore completa, logo, temos que olhar os níveis da árvore

```
Nível 0 --> 2⁰
Nível 1 --> 2¹
Nível 2 --> 2²
...
Nível h --> 2^h
```

logo, há o somar os níveis, obtemos:

$$
N(T) = \sum_{i=0}^{h} 2^i
$$

aplicando um progressão geométrica, obtemos

$$
N(T) = \sum_{i=0}^{h} 2^i =  2^{h+1} - 1
$$