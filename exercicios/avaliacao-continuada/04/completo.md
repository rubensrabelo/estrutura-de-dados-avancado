# Estrutura de Dados Avançado

Rubens Rabêlo Soares

## questão 01

### Resposta:

A família de árvores escolhida foi "A árvore AVL Fibonachi"

#### Defição formal:
A árvore AVL de Fibonacci \(F_h\) de altura \(h\) é a árvore binária de busca AVL com o mínimo número de nós \(N(h)\) possível para essa altura, definida recursivamente como segue:

\[
\begin{cases}
N(0) = 0 \\
N(1) = 1 \\
N(h) = 1 + N(h-1) + N(h-2), & h \gt 1
\end{cases}
\]

Sua estrutura consiste em uma raiz com subárvore esquerda \(F_{h-1}\) (altura \(h-1\)) e subárvore direita \(F_{h-2}\) (altura \(h-2\)), satisfazendo o fator de balanceamento |FB| ≤ 1 em todos os nós. Essa recorrência coincide com a sequência de Fibonacci deslocada, onde \(N(h) = F_{h+2}\) (\(F_0 = 0\), \(F_1 = 1\)).

#### Nó a ser removido:
Em cada $T_k$, removo a folha mais à direita da subárvore direita ($T_{k-2}$).

##### Argumento:
A raiz de $T_k$ tem $bf = -1$ porque o lado esquerdo é 1 nível mais alto que o direito. Quando removo a folha do lado direito, esse lado fica ainda menor, então o $bf$ da raiz vai de $-1$ para $-2$, quebrando o invariante AVL e forçando uma rotação.

Após a rotação, a altura da subárvore da raiz diminui em 1. O nó acima da raiz, que também tinha $|bf| = 1$ (sem nenhuma folga), agora vê sua subárvore encolher e também quebra o invariante — mais uma rotação. Isso se repete em cada nível até o topo.

Isso acontece porque nenhum nó da árvore tem $bf = 0$, ou seja, não existe folga em lugar nenhum. Qualquer redução de altura em uma subárvore imediatamente desbalanceia o nó pai.

Como a árvore tem altura $\mathcal{O}(\log n)$ e ocorre uma rotação por nível, o total de rotações é $\mathcal{O}(\log n)$.

---

## questão 02

### Resposta:

#### 1. Passo a passo do algoritmo

1. **Percorrer em‑ordem \(T_1\) e \(T_2\)**  
   - Uso o percurso em‑ordem em profundidade para visitar todos os nós de \(T_1\) e armazenar suas chaves em um vetor \(V_1\) ordenado.  
   - Repito o mesmo para \(T_2\), gerando um vetor \(V_2\) também ordenado.  
   - Como o percurso em‑ordem visita cada nó exatamente uma vez, essa etapa leva tempo \(O(m+n)\).  

2. **Mesclar os vetores ordenados \(V_1\) e \(V_2\)**  
   - Uso o algoritmo de merge (igual ao do mergesort) para combinar \(V_1\) e \(V_2\) em um único vetor \(V_3\) ordenado.  
   - O merge usa dois apontadores, copiando sempre o menor elemento disponível para \(V_3\), até esgotar um dos vetores e copiar o restante do outro.  
   - Como cada vetor tem tamanho \(m\) e \(n\), o merge leva tempo \(O(m+n)\).  

3. **Construir uma árvore AVL a partir de \(V_3\)**  
   - Aplico o método que vimos em laboratório de construção de árvore quase completa a partir de um vetor ordenado:  
     - Escolho o elemento do meio do intervalo como raiz.  
     - Repito recursivamente à esquerda e à direita com as metades do vetor.  
   - Isso garante que a diferença de altura entre as subárvores de qualquer nó é no máximo 1, ou seja, a condição AVL é satisfeita em todos os nós.  
   - Como cada elemento de \(V_3\) é usado exatamente uma vez na construção, o tempo dessa etapa é \(O(m+n)\).  


#### 2. Pseudocódigo do algoritmo

```text
função intercalarAVL(T1, m, T2, n):
    V1 = perCursoInordem(T1)            // O(m)
    V2 = perCursoInordem(T2)            // O(n)
    V3 = merge(V1, V2)                  // O(m+n)
    T3 = constroiAVL(V3, 0, m+n-1)      // O(m+n)
    retorna T3

função perCursoInordem(T):
    lista = []
    se T ≠ nil:
        lista.append(perCursoInordem(T.esq))
        lista.append(T.chave)
        lista.append(perCursoInordem(T.dir))
    retorna lista

função merge(V1, V2):
    i = 0; j = 0; V3 = []
    enquanto i < m e j < n:
        se V1[i] <= V2[j]:
            V3.append(V1[i])
            i++
        senão:
            V3.append(V2[j])
            j++
    enquanto i < m:
        V3.append(V1[i]); i++
    enquanto j < n:
        V3.append(V2[j]); j++
    retorna V3

função constroiAVL(V, esq, dir):
    se esq > dir:
        retorna nil
    meio = (esq + dir) // 2
    T = novo_no(V[meio])
    T.esq = constroiAVL(V, esq, meio-1)
    T.dir = constroiAVL(V, meio+1, dir)
    retorna T
```


#### 3. Por que a árvore resultante é AVL?

Uma árvore é AVL quando, para todo nó \(v\), o **fator de balanceamento** \(FB(v)\), definido como  
\[
FB(v) = \text{altura}(v.\text{esq}) - \text{altura}(v.\text{dir}),
\]  
satisfaz \(FB(v) \in \{-1, 0, 1\}\).  

Na função `constroiAVL(V, esq, dir)`, o elemento do meio é sempre escolhido como raiz, e as subárvores são construídas sobre intervalos de tamanho aproximadamente iguais. Dessa forma, a altura das subárvores difere no máximo em 1, o que garante que a condição de AVL é mantida em todos os nós da árvore \(T_3\).


### 4. Resposta às dicas

**Dica 1:**  
Dada uma árvore binária de busca \(T\) com \(k\) nós, sabemos acessar todos os nós em ordem crescente em tempo \(O(k)\) usando o percurso em‑ordem em profundidade. Isso me ajuda porque, ao aplicar o percurso em‑ordem em \(T_1\) e \(T_2\), obtenho vetores ordenados \(V_1\) e \(V_2\) contendo todas as chaves das duas árvores. Assim, a intercalação se reduz a combinar dois vetores ordenados, que é um problema clássico resolvido em tempo linear, compatível com o requisito \(O(m+n)\).  

**Dica 2:**  
No laboratório anterior, aprendi a criar uma árvore binária completa a partir de um vetor de chaves ordenado, escolhendo o elemento do meio como raiz e repetindo recursivamente para as metades à esquerda e à direita. O tempo de execução dessa função é \(O(k)\), pois cada chave é usada exatamente uma vez na construção. Essa ideia pode ser usada aqui logo após o merge dos vetores \(V_1\) e \(V_2\): a partir do vetor \(V_3\) ordenado resultante, aplico essa função para construir a árvore AVL final \(T_3\), garantindo que ela seja balanceada e válida, ainda em tempo \(O(m+n)\).  


### 5. Justificativa da complexidade \(O(m+n)\)

- Percorrer em‑ordem \(T_1\) e \(T_2\): cada percurso visita todos os nós exatamente uma vez, logo \(O(m)\) e \(O(n)\), somando \(O(m+n)\).  
- Mesclar \(V_1\) e \(V_2\): o merge de dois vetores ordenados de tamanho \(m\) e \(n\) leva tempo \(O(m+n)\).  
- Construir a árvore a partir de \(V_3\): cada chave do vetor de tamanho \(m+n\) é usada exatamente uma vez na construção recursiva, resultando em tempo \(O(m+n)\).  

Como todas as etapas são executadas em tempo linear em relação ao total de nós das duas árvores, o algoritmo inteiro tem complexidade de tempo \(O(m+n)\), satisfazendo os requisitos da questão.

---

## questão 03

### Resposta:

O maior número possível de nós internos em uma árvore rubro-negra com altura negra \(k\) é \(2^{2k}-1\). O menor número possível é \(2^k-1\).

## **MAIOR: \(2^{2k}-1\)**

### **Construção por níveis (árvore binária perfeita de altura \(2k-1\)):**
```
Nível 0: 2^0 = 1 nó PRETO (raiz)
Nível 1: 2^1 = 2 nós VERMELHO  
Nível 2: 2^2 = 4 nós PRETO
Nível 3: 2^3 = 8 nós VERMELHO
...
Nível 2k-2: 2^(2k-2) nós PRETO
Nível 2k-1: 2^(2k-1) nós VERMELHO
```

**Contagem total**: 
$$\sum_{i=0}^{2k-1} 2^i = \frac{2^{2k}-1}{2-1} = 2^{2k}-1$$

### **Para \(k=2\)**:
```
Nível 0: 1 preto
Nível 1: 2 vermelhos  
Nível 2: 4 pretos
Nível 3: 8 vermelhos
Total: 1 + 2 + 4 + 8 = 15 = 2^4-1
```

### **Verificação da altura negra \(k\)**:
Todo caminho simples da raiz até folha tem **mesmo número de nós pretos**. O caminho mais longo tem nós alternados preto-vermelho (devido à propriedade "nós vermelhos não ocorrem imediatamente consecutivos").

Caminho: raiz(preto) → vermelho → preto(nível 2) → vermelho → NIL  
**Nós pretos da raiz até folha (excluindo raiz)**: 1 preto (nível 2) = \(k=2\) ✓

### **Propriedades RB**:
1. Raiz preta ✓
2. Nó vermelho → filhos pretos (nível ímpar → par) ✓  
3. Sem dois vermelhos consecutivos ✓

## **MENOR: \(2^k-1\)**

### **Construção por níveis (árvore binária perfeita de altura \(k-1\), todos pretos):**
```
Nível 0: 2^0 = 1 nó PRETO
Nível 1: 2^1 = 2 nós PRETO
Nível 2: 2^2 = 4 nós PRETO
...
Nível k-1: 2^(k-1) nós PRETO
```

**Contagem total**:
$$\sum_{i=0}^{k-1} 2^i = \frac{2^k-1}{2-1} = 2^k-1$$

### **Para \(k=2\)**:
```
Nível 0: 1 preto (raiz)
Nível 1: 2 pretos
Total: 1 + 2 = 3 = 2^2-1
```
```
      P (raiz)
     /   \
   P     P
```

### **Verificação da altura negra \(k=2\)**:
Caminho mais curto tem **todos pretos**.  
Caminho longo: raiz → filho(preto) → NIL → **1 preto (filho)** ✓  
Caminho direto: raiz → NIL → **NIL preto** ✓

## **PROVA DO MÍNIMO por Indução Matemática**

**Base \(k=1\)**: Raiz preta, altura negra 1 (NIL). Nós = \(2^1-1 = 1\) ✓

**Hipótese indutiva**: Para \(k-1\), toda RB com altura negra \(k-1\) tem \(\geq 2^{k-1}-1\) nós internos.

**Passo \(k\)**: Raiz é **preta** (propriedade 2).  
**Definição**: Altura negra da raiz = \(1 + \max(\text{altura negra subárvore esquerda}, \text{altura negra subárvore direita}) = k\).

∴ **pelo menos uma** subárvore tem altura negra **exatamente** \(k-1\).

Pela hipótese indutiva: essa subárvore tem \(\geq 2^{k-1}-1\) nós.  
Outra subárvore: \(\geq 0\) nós (NIL possível).  

**Contagem**:
$$1 + (2^{k-1}-1) + 0 = 2^k-1$$

**Não pode ser menor**: Se **ambas** subárvores têm altura negra \(< k-1\), então:  
$$1 + \max(<k-1, <k-1) < k$$ (contradição).

## **PROVA DO MÁXIMO**

Caminho mais longo tem **nós alternados preto-vermelho**. Com \(k\) nós pretos no caminho da raiz, máximo \(k-1\) vermelhos entre eles → **altura total máxima \(2k-1\)**.

Árvore binária perfeita de altura \(2k-1\) tem **exatamente**:
$$\sum_{i=0}^{2k-1} 2^i = 2^{2k}-1$$
nós internos. A coloração alternada satisfaz todas propriedades RB.

## **Conclusão**
- **Maior**: \(2^{2k}-1\) (perfeita altura \(2k-1\), alternada)
- **Menor**: \(2^k-1\) (perfeita altura \(k-1\), todos pretos)

**Ambas construções atingem exatamente altura negra \(k\)** na raiz.

---

## questão 04

### Resposta:

Seja \(b\) o número de nós pretos em qualquer caminho simples de \(x\) até uma folha descendente (propriedade P5).

### Caminho Mais Curto
O caminho de comprimento mínimo contém apenas nós pretos:

\[
\text{Caminho: } x(P) \to P_1(P) \to P_2(P) \to \dots \to P_{b-1}(P) \to \text{NIL}(P)
\]

Número de nós: \(b\)  
Número de arestas: \(s = b - 1\)

**Desigualdade:** \(s \geq b - 1\)

### Caminho Mais Longo
O caminho de comprimento máximo alterna cores, respeitando P4 (sem dois nós vermelhos consecutivos):

\[
\text{Caminho: } x(P) \to R_1(V) \to P_1(P) \to R_2(V) \to \dots \to P_{b-2}(P) \to \text{NIL}(P)
\]

- \(b\) nós pretos (fixo por P5)
- Máximo \(b-1\) nós vermelhos (entre \(b\) pretos, termina em preto)

Total de nós: \(b + (b-1) = 2b - 1\)  
Número de arestas: \(l \leq (2b - 1) - 1 = 2b - 2\)

### Prova da Desigualdade Final

**Passo 1:** Da análise do caminho curto:  
\[
s \geq b - 1
\]

**Passo 2:** Somando 1 em ambos os lados:  
\[
s + 1 \geq b \quad \implies \quad b \leq s + 1
\]

**Passo 3:** Multiplicando por 2 (preserva desigualdade):  
\[
2b \leq 2(s + 1)
\]

**Passo 4:** Subtraindo 2:  
\[
2b - 2 \leq 2(s + 1) - 2
\]

**Passo 5:** Simplificando o lado direito:  
\[
2(s + 1) - 2 = 2s + 2 - 2 = 2s
\]

**Passo 6:** Combinando com o limite do caminho longo:  
\[
l \leq 2b - 2 \leq 2s
\]

**Conclusão:** \(l \leq 2s\)

---

## questão 05

### Resposta:

## Pseudocódigo

```
ROTACAO-DIREITA(T, x)
    y ← x.esquerda
    x.esquerda ← y.direita
    se y.direita ≠ NIL então
        y.direita.pai ← x
    y.pai ← x.pai
    se x.pai = NIL então
        T.raiz ← y
    senão se x = x.pai.direita então
        x.pai.direita ← y
    senão
        x.pai.esquerda ← y
    y.direita ← x
    x.pai ← y
```