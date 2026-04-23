O número de acessos ao disco necessários para a maioria das operações em uma árvore-B é proporcional à altura da árvore-B.

> ### **Teorema 1**
>
> Se $n \ge 1$, então, para qualquer árvore-B *T* com *n* chaves e grau mínimo $t \ge 2$:
>
> $$
> h \le \log_t \left(\frac{n + 1}{2}\right)
> $$


### **Prova**

Por definição, a raiz de uma árvore-B não vazia *T* contém pelo menos uma chave, e todos os outros nós contêm pelo menos $t - 1$ chaves. Seja *h* a altura de *T*.

Para obter o **menor número possível de chaves**, consideramos que todos os nós (exceto a raiz) possuem exatamente $t - 1$ chaves.

#### Quantidade de nós por nível:

Seja N = igual a nível e QN a quantidade de nós

$$
\begin{aligned}
\text{N 0:} & \quad QN = 1 \\
\text{N 1:} & \quad QN = 2 \\
\text{N 2:} & \quad QN = 2t \\
\text{N 3:} & \quad QN = 2t^2 \\
& \quad \vdots \\
\text{N } h: & \quad QN = 2t^{h-1}
\end{aligned}
$$


#### Soma total de chaves:

$$
n \ge 1 + \sum_{i=1}^{h} 2t^{i-1}
$$

Aplicando a soma de progressão geométrica:

$$
n \ge 1 + 2 \cdot \frac{t^h - 1}{t - 1}
$$

Simplificando:

$$
n \ge 1 + 2t^h - 1
$$

$$
n - 1 \ge 2t^h
$$

$$
\frac{n - 1}{2} \ge t^h
$$


#### Aplicando logaritmo em ambos os lados:

$$
\log_t \left(\frac{n - 1}{2}\right) \ge \log_t (t^h)
$$

$$
\log_t \left(\frac{n - 1}{2}\right) \ge h
$$

$$
h \le \log_t \left(\frac{n - 1}{2}\right)
$$


Isso conclui a prova.
