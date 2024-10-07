| n   | h(n)  |
| --- | ----- |
| 2   | 30    |
| 4   | 80    |
| 8   | 160   |
| 16  | 220   |
| 32  | 550   |
| 64  | 1000  |
| 128 | 1200  |
| 256 | 34000 |
| 512 | 40000 |

MMQ - O(n)

f(n) = a + b*n

30 = a + b*2
80 = a + b*4
...
40000 = a + b*512

f(n) = 5 + 40n

e = f(n) - h(n) <- Menor possível

A)
|     | c1  | c2  |
| --- | --- | --- |
| l1  | 1   | 2   |
| l2  | 1   | 4   |
| ... | ... | ... |
| l9  | 1   | 512 |

x)
|     |
| --- |
| a   |
| b   |

y)
| h(n)  |
| ----- |
| 30    |
| 80    |
| 160   |
| 220   |
| 550   |
| 1000  |
| 1200  |
| 34000 |
| 40000 |

Ax = y
(A^T * A)x = A^T*y
inv(A^T * A)(A^T * A)*x = inv(A^T * A)*A^T*y
x = inv(A^T * A)*A^T*y

O(a + b*n) = O(n)

"Como seria a curva, caso os pontos obedecessem uma função linear"

Erro:

e(n)^2 = ((a + b n) - h(n))^2

E = sqrt(sum(1;n;e(n)^2/n)) <--- RMSE



O(a + b*n + c*n^2) = O(n^2) <-- 

a) Calcularia os tempos médios
b) Ajustaria a curva para diversar funções:
    i) Linear
    ii) Quadrática
    iii) log_linear
    iv) Exponencial
    ...
    v) fatorial
c) Calcularia o RMSE de todas as funções anteriores
d) A complexidade seria da função com menor RMSE.











