![Imagem da questão 04](./img/questao-04.png)

### Resposta:

#### Ideia da prova

Para provar que a altura é \(O(\log n)\), precisamos mostrar que o número mínimo de nós de uma árvore 2-balanceada de altura \(h\) cresce exponencialmente com \(h\).

Se o número de nós cresce exponencialmente, então a altura cresce logaritmicamente.


#### Número mínimo de nós

Seja \(N(h)\) o número mínimo de nós de uma árvore 2-balanceada de altura \(h\).

Para minimizar o número de nós, devemos deixar a árvore o mais “desbalanceada” possível, respeitando:

$$
|h_D(v) - h_E(v)| \leq 2
$$

Então, a menor árvore possível de altura \(h\) ocorre quando:

- uma subárvore tem altura \(h-1\)
- a outra tem altura \(h-3\)

Logo:

$$
N(h) = 1 + N(h-1) + N(h-3)
$$



#### Casos base

Para pequenas alturas:

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

Da recorrência:

$$
N(h) = 1 + N(h-1) + N(h-3)
$$

podemos observar que:

$$
N(h) \geq N(h-1) + N(h-3)
$$

Essa recorrência cresce de forma exponencial, semelhante à sequência de Fibonacci.

Portanto, existe uma constante \(c > 1\) tal que:

$$
N(h) \geq c^h
$$


#### Relação entre altura e número de nós

Sabemos que:

$$
N(h) \geq c^h
$$

e como \(n\) é o número de nós da árvore:

$$
n \geq c^h
$$

Aplicando logaritmo:

$$
\log n \geq h \log c
$$

Isolando \(h\):

$$
h \leq \frac{\log n}{\log c}
$$

Como \(\log c\) é constante:

$$
h = O(\log n)
$$


Portanto, o número mínimo de nós de uma árvore 2-balanceada cresce exponencialmente com a altura.

Assim, a altura cresce de forma logarítmica em relação ao número de nós.

Portanto,

$$
h = O(\log n)
$$

Logo, **toda árvore 2-balanceada possui altura da ordem de \(O(\log n)\)**.