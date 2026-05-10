### Utilizando o Programa Principal

Ao executar:

```bash
./app
```

o seguinte menu será exibido:

```text
========== MENU ==========
1 - Criar conjunto
2 - Inserir elemento
3 - Remover elemento
4 - Mostrar conjunto
5 - Contains
6 - Minimum
7 - Maximum
8 - Successor
9 - Predecessor
10 - Union
11 - Intersection
12 - Difference
13 - Size
14 - Empty
15 - Clear
0 - Sair
```


#### Exemplo Completo

**1. Criar conjunto**

Entrada:

```text
1
```

Saída:

```text
Conjunto criado com ID 0
```

**2. Inserir múltiplos valores**

Entrada:

```text
2
0
10 5 20 7 -1 30 q
```

Explicação:

- `0` → ID do conjunto
- `q` → encerra inserção


**3. Mostrar árvore**

Entrada:

```text
4
0
```

Saída esperada:

```text
    20(B)
        10(R)
7(B)
        5(R)
    -1(B)
```

**4. Testar Contains**

Entrada:

```text
5
0
10
```

Saída:

```text
true
```

**5. Testar Minimum**

Entrada:

```text
6
0
```

Saída:

```text
-1
```

**6. Testar Maximum**

Entrada:

```text
7
0
```

Saída:

```text
30
```

**7. Testar Successor**

Entrada:

```text
8
0
10
```

Saída:

```text
20
```

**8. Testar Predecessor**

Entrada:

```text
9
0
10
```

Saída:

```text
7
```

**9. Remover elemento**

Entrada:

```text
3
0
20
```

**10. Mostrar árvore novamente**

Entrada:

```text
4
0
```

**11. Criar segundo conjunto**

Entrada:

```text
1
```

Saída:

```text
Conjunto criado com ID 1
```

**12. Inserir elementos no conjunto 1**

Entrada:

```text
2
1
20 30 40 q
```

**13. União**

Entrada:

```text
10
0
1
```

**14. Interseção**

Entrada:

```text
11
0
1
```

**15. Diferença**

Entrada:

```text
12
0
1
```

**16. Limpar conjunto**

Entrada:

```text
15
0
```

**17. Encerrar programa**

Entrada:

```text
0
```