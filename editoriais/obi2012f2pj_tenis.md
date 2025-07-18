## Tira-teima

Para resolver o problema basta determinar se a bola caiu dentro ou fora da quadra, o que equivale a 
verificar as condições $X\in[0, 432]$ e $Y\in[0,468]$. Nas linguagens de programação tradicionais, isto
por se feio por meio de uma condicional (por exemplo, `if-else`) cuja condição é formada pela conjunção
(__e__ lógico) de quatro desigualdades:

1. $0\leq X$
1. $X\leq 432$
1. $0\leq Y$
1. $Y\leq 468$

Esta solução tem complexidade $O(1)$.

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>

int main()
{
    int X, Y;
    scanf("%d %d", &X, &Y);

    if (0 <= X && X <= 432 && 0 <= Y && Y <= 468)
        printf("dentro\n");
    else
        printf("fora\n");

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em C++</b></summary>

```cpp
#include <bits/stdc++.h>

using namespace std;

auto solve(int X, int Y)
{
    return 0 <= X and X <= 432 and 0 <= Y and Y <= 468 ? "dentro" : "fora";
}

int main()
{
    int X, Y;
    cin >> X >> Y;

    cout << solve(X, Y) << '\n';

    return 0;
}
```
</details>

<details>
    <summary><b>Solução em Python</b></summary>

```Python
X, Y = map(int, input().split())

if 0 <= X and X <= 432 and 0 <= Y and Y <= 468:
    print("dentro");
else:
    print("fora");
```
</details>

<details>
    <summary><b>Solução em Java</b></summary>

```java
import java.util.Scanner;

public class solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int X = scanner.nextInt();
        int Y = scanner.nextInt();

        if (0 <= X && X <= 432 && 0 <= Y && Y <= 468)
            System.out.println("dentro");
        else
            System.out.println("fora");
    }
}
```
</details>
