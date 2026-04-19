![Imagem da questão 03](./img/questao-03.png)

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
$$1 + (2^{k-1}-1) + (2^{k-1}-1) = 2*2^{k-1}-1 = 2^k-1$$

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