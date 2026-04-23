**Questão 01)**

**Resposta:**


    A[26] --> B[17]
    A --> C[41]

    B --> D[14]
    B --> E[21]

    D --> F[10]
    D --> G[16]

    F --> H[7]
    F --> I[12]

    H --> J[3]
    H --> NIL1[NIL]

    J --> NIL2[NIL]
    J --> NIL3[NIL]

    I --> NIL4[NIL]
    I --> NIL5[NIL]

    G --> K[15]
    G --> NIL6[NIL]

    K --> NIL7[NIL]
    K --> NIL8[NIL]

    E --> L[19]
    E --> M[23]

    L --> NIL9[NIL]
    L --> N[20]

    N --> NIL10[NIL]
    N --> NIL11[NIL]

    M --> NIL12[NIL]
    M --> NIL13[NIL]

    C --> O[30]
    C --> P[47]

    O --> Q[28]
    O --> R[38]

    Q --> NIL14[NIL]
    Q --> NIL15[NIL]

    R --> S[35]
    R --> T[39]

    S --> NIL16[NIL]
    S --> X[36]

    T --> NIL18[NIL]
    T --> NIL19[NIL]

    P --> NIL20[NIL]
    P --> NIL21[NIL]

    %% CORES
    %% Pretos
    style A fill:#000,color:#fff
    style C fill:#000,color:#fff
    style D fill:#000,color:#fff
    style E fill:#000,color:#fff
    style G fill:#000,color:#fff
    style H fill:#000,color:#fff
    style I fill:#000,color:#fff
    style L fill:#000,color:#fff
    style M fill:#000,color:#fff
    style P fill:#000,color:#fff
    style Q fill:#000,color:#fff
    style R fill:#000,color:#fff

    %% Vermelhos
    style B fill:#ff0000,color:#fff
    style F fill:#ff0000,color:#fff
    style J fill:#ff0000,color:#fff
    style K fill:#ff0000,color:#fff
    style N fill:#ff0000,color:#fff
    style O fill:#ff0000,color:#fff
    style S fill:#ff0000,color:#fff
    style T fill:#ff0000,color:#fff

    %% NIL (pretos)
    style NIL1 fill:#000,color:#fff
    style NIL2 fill:#000,color:#fff
    style NIL3 fill:#000,color:#fff
    style NIL4 fill:#000,color:#fff
    style NIL5 fill:#000,color:#fff
    style NIL6 fill:#000,color:#fff
    style NIL7 fill:#000,color:#fff
    style NIL8 fill:#000,color:#fff
    style NIL9 fill:#000,color:#fff
    style NIL10 fill:#000,color:#fff
    style NIL11 fill:#000,color:#fff
    style NIL12 fill:#000,color:#fff
    style NIL13 fill:#000,color:#fff
    style NIL14 fill:#000,color:#fff
    style NIL15 fill:#000,color:#fff
    style NIL16 fill:#000,color:#fff
    style NIL17 fill:#000,color:#fff
    style NIL18 fill:#000,color:#fff
    style NIL19 fill:#000,color:#fff
    style NIL20 fill:#000,color:#fff
    style NIL21 fill:#000,color:#fff
```

Em ambos os casos, a árvore deixa de ser uma árvore rubro-negra.
Se o nó inserido for vermelho, ocorre violação da propriedade 4, pois o nó 36 teria pai 35 também vermelho.
Se o nó inserido for preto, ocorre violação da propriedade 5, pois os caminhos da raiz até as folhas passam a ter quantidades diferentes de nós pretos (black-height inconsistente).