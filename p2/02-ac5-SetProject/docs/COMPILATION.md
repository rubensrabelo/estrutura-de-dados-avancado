### Compilação e Execução

#### Usando Makefile

##### Compilar programa principal

```bash
make
```


##### Executar programa principal

```bash
make run
```

ou:

```bash
./app
```


##### Compilar testes

```bash
make tests
```


##### Executar testes

```bash
make run-tests
```

ou:

```bash
./tests
```


##### Limpar executáveis

```bash
make clean
```

---

### Compilação Manual

#### Programa principal

```bash
g++ -std=c++17 -Ilib/include \
main.cpp \
lib/src/Node.cpp \
lib/src/RBTree.cpp \
lib/src/Set.cpp \
-o app
```

Executar:

```bash
./app
```


#### Testes automáticos

```bash
g++ -std=c++17 -Ilib/include \
test/tests.cpp \
lib/src/Node.cpp \
lib/src/RBTree.cpp \
lib/src/Set.cpp \
-o tests
```

Executar:

```bash
./tests
```