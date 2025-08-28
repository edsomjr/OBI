## Arara!

A solução do problema é baseada em duas observações:

1. devemos sempre colocar uma arara na gaiola 1;
2. devemos deixar o espaço mínimo necessário entre as araras.

Em relação à primeira observação, se posicionarmos a primeira arara nas gaiolas 2, 3, 4 ou 5, as gaiolas
à esquerda ficarão inutilizadas, por não guardarem a distância mínima entre duas araras. A segunda
observação também evita que gaiolas fiquem inutilizadas.

As duas observações estabelecem que as araras devem ser posicionadas nas gaiolas 1, 6, 11, 16, 21, .... Esta
sequência é uma progressão aritmética de razão 5 e termo inicial 1, que pode ser expressa pela recorrência

$$
a_k = a_1 + (k - 1)r = 1 + 5(k - 1)
$$

Para determinar o maior elemento da sequência que é menor ou igual a $M$ devemos resolver a desigualdade
$a_k \leq M$, o que nos dá

$$
1 + 5(k - 1) \leq M,
$$
que pode ser reescrita como 

$$
5(k - 1) \leq M - 1
$$
e daí
$$
k \leq 1 + \frac{M - 1}{5}
$$

A resposta do problema será `S` se $1 + \lfloor\frac{M - 1}{5}\rfloor\leq N$, e `N`, caso contrário. Esta solução tem complexidade $O(1)$.

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    int araras = 1 + (M - 1)/5;

    if (araras >= N)
        printf("S\n");
    else
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

auto solve(int N, int M)
{
    return 1 + (M - 1)/5 >= N ? 'S' : 'N';
}

int main()
{
    int N, M;
    cin >> N >> M;

    cout << solve(N, M) << '\n';

    return 0;
}
```
</details>

<details>
    <summary><b>Solução em Python</b></summary>

```Python
N, M = map(int, input().split())
araras = 1 + (M - 1)/5

if araras >= N:
    print("S")
else:
    print("N")
```
</details>

<details>
    <summary><b>Solução em Java</b></summary>

```Java
import java.util.Scanner;

public class solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int araras = 1 + (M - 1)/5;

        if (araras >= N)
            System.out.println("S");
        else
            System.out.println("N");
    }
}
```
</details>
