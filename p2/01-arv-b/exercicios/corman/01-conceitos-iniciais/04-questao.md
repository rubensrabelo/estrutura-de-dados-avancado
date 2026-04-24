**18.1-4** - As a function of the minimum degree t, what is the maximum number of keys that can be stored in a B-tree of height h?

**Resposta:**

Como queremos o máximo de chaves, iremos utilizar a fómula de $K_{max} = 2t - 1$

Logo, olhando para o níveis (N) temos as seguintes quantidades de nós (QN):

$$
\begin{aligned}
\text{N 0:} & \quad QN = 1 \\
\text{N 1:} & \quad QN = 2t \\
\text{N 2:} & \quad QN = 2t^2 \\
\text{N 3:} & \quad QN = 2t^3 \\
& \quad \vdots \\
\text{N } h: & \quad QN = 2t^h
\end{aligned}
$$

Dessa forma, podemos somar nível por nível resultando em:

$$
n \le 1 + \sum_{i=0}^{h} 2t^{i}
$$

Agora, multiplicamos por $(2t - 1)$, indicando que cada nós tem o seu máximo de chaves,

$$
n \le (2t - 1)(1 + \sum_{i=0}^{h} 2t^{i})
$$

Realizando a progressão geométrica, temos:

$$
\sum_{i=1}^{h} 2t^{i}
$#

temos uma PG de primeiro termo $a_1 = 2t$, razão $r = t$ e $h$ termos. A soma é dada por:

$$
\sum_{i=1}^{h} 2t^{i} = \frac{2t(t^h - 1)}{t - 1}
$$ 

Substituindo na expressão de $n$:

$$
n \le (2t - 1) \left( 1 + \frac{2t(t^h - 1)}{t - 1} \right)
$$ 

Realizando o MMC dentro dos parênteses para simplificar a expressão:

$$
n \le (2t - 1) \left( \frac{(t - 1) + 2t(t^h - 1)}{t - 1} \right) \\
n \le (2t - 1) \left( \frac{t - 1 + 2t^{h+1} - 2t}{t - 1} \right) \\
n \le (2t - 1) \left( \frac{2t^{h+1} - t - 1}{t - 1} \right)
$$

Aplicando a distributiva no numerador:

$$
n \le \frac{4t^{h+2} - 2t^2 - 2t - 2t^{h+1} + t + 1}{t - 1}
$$ 

Ao simplificar a expressão polinomial (ou realizar a divisão por $t-1$), chegamos ao resultado final:
$$
n \le 2t^{h+1} - 1
$$

Para expressar a altura $h$ em função de $n$ e $t$, isolamos o termo exponencial e aplicamos o $\log_t$:

$$
n + 1 \le 2t^{h+1}\\
\frac{n + 1}{2} \le t^{h+1} \\
\log_t \left( \frac{n + 1}{2} \right) \le h + 1 \\
h \ge \log_t \left( \frac{n + 1}{2} \right) - 1
$$ 
