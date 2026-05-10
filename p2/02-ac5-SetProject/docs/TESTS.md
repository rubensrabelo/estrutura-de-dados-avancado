### Testes Automáticos

O projeto possui testes automáticos em:

```bash
test/tests.cpp
```

#### Compilar testes

```bash
make tests
```


#### Executar testes

```bash
make run-tests
```

ou:

```bash
./tests
```

#### Operações testadas

Os testes verificam:

- Insert
- Erase
- Contains
- Minimum
- Maximum
- Successor
- Predecessor
- Union
- Intersection
- Difference
- Empty
- Clear
- Size

#### Exemplo de saída

```text
===== INICIANDO TESTES =====

[TESTE] Insert + Size
Esperado: 3 | Obtido: 3

[TESTE] Contains
Esperado: 1 | Obtido: 1

[TESTE] Minimum / Maximum
Min esperado: 5 | Obtido: 5
Max esperado: 20 | Obtido: 20

===== FIM DOS TESTES =====
```