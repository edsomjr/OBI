## Receita de Bolo

De acordo com a receita apresentada, a quantidade de farinha é suficiente para fazer $A/2$ bolos,
os ovos $B/3$ bolos e o leite $C/5$ bolos. Assim, a quantidade de bolos que podem ser feitos com os
três ingredientes é dada pelo menor dentre estes três valores.

Linguagens como C++, Python e Java já disponibilizam, em usa API padrão, uma função para determinar o
mínimo entre dois números. A linguagem C não tem função equivalente em sua biblioteca padrão, mas ela
pode ser implementada da seguinte forma:

```c
int min(int x, int y)
{
    return x <= y ? x : y;
}
```

Esta solução tem complexidade $O(1)$.

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>

int min(int x, int y)
{
    return x <= y ? x : y;
}

int main()
{
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    int ans = min(A / 2, min(B / 3, C / 5));

    printf("%d\n", ans);

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em C++</b></summary>

```cpp
#include <bits/stdc++.h>

using namespace std;

auto solve(int A, int B, int C)
{
    return min({ A/2, B/3, C/5 });
}

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    cout << solve(A, B, C) << '\n';

    return 0;
}
```
</details>

<details>
    <summary><b>Solução em Python</b></summary>

```Python
A, B, C = map(int, input().split())
print(min([A//2, B//3, C//5]))
```
</details>

<details>
    <summary><b>Solução em Java</b></summary>

```java
import java.util.Scanner;

public class solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();

        int ans = Math.min(A/2, Math.min(B/3, C/5));

        System.out.println(ans);
    }
}
```
</details>
