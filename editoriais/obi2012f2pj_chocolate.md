## Chocolate

O problema consiste em determinar o menor número $k$ de divisões da barra de chocolate tal que cada
pedaço tenha lado menor ou igual a 2 cm. Para cada divisão feita, um pedaço gera 4 novos pedaços, de modo
que a resposta do problema será igual a $4k$.

Há duas formas de se determinar o valor de $k$. A primeira maneira é simular as divisões sucessivas, até
que o resultado da divisão seja estritamente menor do que 2. Esta solução tem complexidade $O(\log N)$
(veja a solução Python).

Outra forma é observar que $k = \log_2 N$ e usar a função `log2()`, disponível na biblioteca `math.h` da
linguagem C ou na biblioteca `cmath` da linguagem C++. Esta solução tem complexidade $O(1)$, assumindo
que tais funções consigam computar $\log_2 N$ em $O(1)$ (veja a solução em C++).

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int _2k = 1, ans = 1;

    while (2 * _2k <= N)
    {
        _2k *= 2;
        ans *= 4;
    }

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

auto solve(int N)
{
    int k = (int) floor(log2(N));

    return 1 << (2*k);
}

int main()
{
    int N;
    cin >> N;

    cout << solve(N) << '\n';

    return 0;
}
```
</details>

<details>
    <summary><b>Solução em Python</b></summary>

```Python
N = int(input())
ans = 1

while N >= 2:
    N /= 2
    ans *= 4

print(ans)
```
</details>

<details>
    <summary><b>Solução em Java</b></summary>

```java
import java.util.Scanner;

public class solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int ans = 1, pot = 1;

        while (2*pot <= N)
        {
            ans *= 4;
            pot *= 2;
        }

        System.out.println(ans);
    }
}
```
</details>
