## Cafeteria

A caneca do cliente tem capacidade de $C$ ml. Se Felipe preparar $k$ doses de café, os $C - kD$ ml 
restantes serão preenchidos com leite. Como o cliente deseja no mínimo $A$ e, no máximo, $B$ ml de leite,
a resposta do problema será `S` se $A\leq C - kD\leq B$. Falta determinar, porém, os valores que a 
variável $k$ pode assumir.

Isto pode ser feito de duas maneiras. A primeira delas é usar um laço de repetição (`for` ou `while`) que,
a cada iteração, atribuirá um valor para $k$. O valor inicial deve ser 1 e o máximo pode ser igual a
$C$ (porque Felipe tem que preparar ao menos uma dose de café e a caneca tem que comportar o café 
preparado). Para cada valor, se a condição $A\leq C - kD\leq B$ for verdadeira, o laço pode ser 
interrompido e a resposta será `S`. Se o laço se encerrar sem que a condição se torne verdadeira ao
menos uma vez, a resposta será `N`. Esta abordagem tem complexidade $O(C)$ (veja a solução em C).

A segunda forma de se abordar o problema é observar que, para que a quantidade de leite seja menor ou
igual a $B$, é preciso que $C - kD \leq B$. Manipulando esta desigualdade, obtemos

$$
k \geq \frac{C - B}{D}
$$

Assim, o primeiro valor de $k$ que satisfaz a desigualdade é o menor inteiro que é maior ou igual a 
$(C - B)/D$. Se este valor for tal que $A\leq C - kD$, a resposta será `S`, caso contrário será `N`
(pois o próximo valor válido seria o sucessor de $k$ e aumentar $k$ significar colocar mais café:
observe que a segunda condição falha quando não há leite suficiente). Esta solução tem
complexidade $O(1)$ (veja a solução em C++).

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>

int main()
{
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);

    for (int left = C - D; left >= 0; left -= D)
    {
        if (A <= left && left <= B)
        {
            printf("S\n");
            return 0;
        }
    }

    printf("N\n");

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em C++</b></summary>

```cpp
#include <bits/stdc++.h>

using namespace std;

auto solve(int A, int B, int C, int D)
{
    int k = (C - B + D - 1)/D;

    return (C - k*D >= A) ? 'S' : 'N';
}

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    cout << solve(A, B, C, D) << '\n';

    return 0;
}
```
</details>

<details>
    <summary><b>Solução em Python</b></summary>

```Python
A = int(input())
B = int(input())
C = int(input())
D = int(input())

k = (C - B + D - 1)//D

if C - k*D >= A:
    print('S')
else:
    print('N')
```
</details>

<details>
    <summary><b>Solução em Java</b></summary>

```Java
import java.util.Scanner;

public class solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();
        int D = scanner.nextInt();

        for (int left = C - D; left >= 0; left -= D) {
            if (A <= left && left <= B) {
                System.out.println("S");
                System.exit(0);
            }
        }

        System.out.println("N");
    }
}
```
</details>
