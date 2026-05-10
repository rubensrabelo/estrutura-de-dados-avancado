# Set Project

## Descrição

Este projeto implementa uma estrutura de dados **Set (conjunto dinâmico de inteiros)** utilizando uma **Árvore Rubro-Negra (Red-Black Tree)**.

As principais operações possuem complexidade:

- Insert → O(log n)
- Erase → O(log n)
- Contains → O(log n)
- Minimum → O(log n)
- Maximum → O(log n)
- Successor → O(log n)
- Predecessor → O(log n)


## Estrutura do Projeto

```bash
SetProject/
│
├── main.cpp
│
├── docs/
│   ├── README.md
│   ├── COMPILATION.md
│   ├── MAIN_USAGE.md
│   └── TESTS.md
│
├── test/
│   └── tests.cpp
│
├── lib/
│   ├── include/
│   │   ├── Node.h
│   │   ├── RBTree.h
│   │   └── Set.h
│   │
│   └── src/
│       ├── Node.cpp
│       ├── RBTree.cpp
│       └── Set.cpp
│
└── Makefile
```


## Documentação

### Compilação e execução

Ver:

[Como compilar o projeto](docs/COMPILATION.md)


### Utilização do menu principal

Ver:

[Exemplo de uso do programa](docs/MAIN_USAGE.md)


## Testes automáticos

Ver:

[Executar testes automáticos](docs/TESTS.md)