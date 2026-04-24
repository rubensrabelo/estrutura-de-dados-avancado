**Anotações:**

- Inserir em uma folha existente
- Operação para quebrar uma folha (com 2t - 1) ao redor da sua mediana, resultando em duas folhas (t - 1). A mediana é movito para o nó acima, para identificar o ponteiro que irá para as duas folhas resultante
- Divisão ocorre conforme estiver percorrendo a àrvore para não ter retrabalho na volta
- A Estratégia de "Uma Única Passagem" (Single Pass)

**Pseudocódigo**

**Estratégia de dividir:**

```c++
B-TREE-SPLIT-CHILD(x, i)
    z = ALLOCATE-NODE()        // Cria um novo nó vazio 'z' que receberá metade de 'y'
    y = x.c[i]                 // 'y' é o i-ésimo filho de 'x' (o nó cheio que será dividido)
    z.leaf = y.leaf            // Se 'y' for folha, 'z' também será; se não, 'z' também não será
    z.n = t - 1                // 'z' terá o número mínimo de chaves (metade superior de 'y')

    // Transfere as t-1 chaves maiores de 'y' para o novo nó 'z'
    for j = 1 to t - 1
        z.key[j] = y.key[j + t]

    // Se 'y' não for folha, transfere também os t filhos correspondentes para 'z'
    if not y.leaf
        for j = 1 to t
            z.c[j] = y.c[j + t]

    y.n = t - 1                // Ajusta o número de chaves de 'y' (ele agora só tem a metade inferior)

    // Desloca os filhos de 'x' para a direita para abrir espaço para o novo filho 'z'
    for j = x.n + 1 downto i + 1
        x.c[j + 1] = x.c[j]

    x.c[i + 1] = z             // Conecta o novo nó 'z' como filho de 'x' logo após 'y'

    // Desloca as chaves de 'x' para a direita para abrir espaço para a chave que vai subir de 'y'
    for j = x.n downto i
        x.key[j + 1] = x.key[j]

    x.key[i] = y.key[t]        // Sobe a chave mediana de 'y' para o pai 'x'
    x.n = x.n + 1              // Incrementa a contagem de chaves do pai 'x'

    // Salva as alterações de todos os nós modificados no disco
    DISK-WRITE(y)              // Salva 'y' (agora menor)
    DISK-WRITE(z)              // Salva 'z' (o novo nó)
    DISK-WRITE(x)              // Salva 'x' (que ganhou uma chave e um filho)
```

**Dividir a raiz**

```c++
B-TREE-SPLIT-ROOT(T)
    s = ALLOCATE-NODE()        // Cria um novo nó 's' (este nó será a nova raiz)
    s.leaf = FALSE             // Como ele ficará acima da antiga raiz, ele não é folha
    s.n = 0                    // Inicialmente não tem chaves
    s.c[1] = T.root            // O primeiro filho da nova raiz 's' passa a ser a raiz antiga
    T.root = s                 // Atualiza o ponteiro da árvore T para que 's' seja a nova raiz oficial
    
    // Agora que 's' é o pai (não cheio) da raiz antiga (cheia),
    // chamamos o SPLIT-CHILD para dividir o filho número 1 de 's'
    B-TREE-SPLIT-CHILD(s, 1)   
    
    return s                   // Retorna a nova raiz já preparada
```

**Inserir**

```c++
B-TREE-INSERT(T, k)
    r = T.root                   // 'r' recebe a raiz atual da árvore T
    
    // Verifica se a raiz está completamente cheia (2t - 1 chaves)
    if r.n == 2 * t - 1
        // CASO A RAIZ ESTEJA CHEIA: A árvore vai aumentar de altura
        s = B-TREE-SPLIT-ROOT(T) // Cria nova raiz e divide a antiga (que vira filha de s)
        
        // Após a raiz ser dividida, chamamos a inserção no nó 's' (que agora é a raiz não cheia)
        B-TREE-INSERT-NONFULL(s, k)
        
    else
        // CASO A RAIZ NÃO ESTEJA CHEIA:
        // Chamamos a inserção diretamente nela, que descerá até a folha apropriada
        B-TREE-INSERT-NONFULL(r, k)
```

**Inserção em Nós Não Cheios**

```c++
B-TREE-INSERT-NONFULL(x, k)
    i = x.n                          // Começa do último índice de chaves do nó x
    
    if x.leaf                        // CASO 1: O nó atual é uma FOLHA
        // Empurra as chaves maiores que 'k' para a direita para abrir espaço
        while i >= 1 and k < x.key[i]
            x.key[i + 1] = x.key[i]
            i = i - 1
        
        x.key[i + 1] = k             // Insere a nova chave 'k' na posição correta
        x.n = x.n + 1                // Incrementa a contagem de chaves do nó
        DISK-WRITE(x)                // Salva a alteração da folha no disco

    else                             // CASO 2: O nó atual é INTERNO
        // Encontra em qual filho a chave 'k' deve ser inserida
        while i >= 1 and k < x.key[i]
            i = i - 1
        i = i + 1                    // Ajusta o índice para o filho apropriado
        
        DISK-READ(x.c[i])            // Lê o nó filho do disco para a memória RAM
        
        // ESTRATÉGIA PREVENTIVA: Se o filho estiver cheio, divide-o agora
        if x.c[i].n == 2 * t - 1
            B-TREE-SPLIT-CHILD(x, i) // Divide o filho cheio em dois
            
            // Após o split, a chave mediana subiu para 'x'. 
            // Verificamos se 'k' deve ir para o filho da esquerda ou da direita.
            if k > x.key[i]
                i = i + 1
        
        // Continua a descida recursiva para o próximo nível
        B-TREE-INSERT-NONFULL(x.c[i], k)

```