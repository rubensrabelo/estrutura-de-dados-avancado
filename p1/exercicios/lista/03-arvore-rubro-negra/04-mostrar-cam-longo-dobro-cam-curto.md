## Questão 04)

### Resposta

Por definição, o comprimento de um caminho (C) é o número de arestas nele. Assim, um caminho com \( n \) nós tem comprimento \( n - 1 \).

**Caminho mais curto:** Consideramos apenas nós pretos. Para um nó \( x \) com altura negra \( bh(x) = k \) (onde \( k \geq 1 \)), o caminho até uma folha NIL passa por exatamente \( k \) nós pretos além de \( x \), totalizando \( k + 1 \) nós pretos.

\[
\text{C} = (k + 1) - 1 = k
\]

**Caminho mais longo:** Há alternância entre nós pretos e vermelhos, maximizando os nós vermelhos sem violar a propriedade P5. Cada um dos \( k \) nós pretos (além de \( x \)) pode ter no máximo um nó vermelho entre eles, resultando em \( k \) nós pretos + \( k \) nós vermelhos + o nó \( x \), totalizando \( 2k + 1 \) nós.

\[
\text{C} = (2k + 1) - 1 = 2k
\]

Portanto, o comprimento do caminho mais longo de \( x \) até uma folha NIL é no máximo o dobro do caminho mais curto.
