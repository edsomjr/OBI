## Pizzaria

Segundo o texto do problema, uma pizza grande tem 8 pedaços e uma pizza pequena tem 4 pedaços.
Assim, $G$ pizzas grandes e $P$ pizzas pequenas totalizam $8G + 4P$ pedaços. Excluindo deste total
Larissa e sua mãe, ainda podem ser convidados $8G + 4P - 2$ amigos.

Esta solução em complexidade $O(1)$.

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>

int main()
{
    int G, P;
    scanf("%d %d", &G, &P);

    printf("%d\n", 8*G + 4*P - 2);

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em C++</b></summary>

```cpp
#include <bits/stdc++.h>

using namespace std;

auto solve(int G, int P)
{
    return 8*G + 4*P - 2;
}

int main()
{
    int G, P;
    cin >> G >> P;

    cout << solve(G, P) << '\n';

    return 0;
}
```
</details>

<details>
    <summary><b>Solução em Python</b></summary>

```Python
G = int(input())
P = int(input())
print(8*G + 4*P - 2)
```
</details>

<details>
    <summary><b>Solução em Java</b></summary>

```Java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int G = scanner.nextInt();
        int P = scanner.nextInt();
        int ans = G * 8 + P * 4 - 2;

        System.out.println(ans);
    }
}
```
</details>
