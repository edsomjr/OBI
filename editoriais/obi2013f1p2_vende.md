## Vende-se

O problema consiste em determinar a distância máxima entre os prédios remanescentes, após a exclusão de $K$ deles. Há 

$$
C_N^K = \binom{N}{K} = \frac{N!}{K!(N - K)!}
$$

maneiras de se escolher os prédios a serem resolvidos. Uma solução que avalia todas estas possíveis remoções leva a um veredito TLE, exceto
na subtarefa 1, que restringe $N$ a, no máximo, 10, e que vale 30 pontos.

Para resolver o problema no caso geral, considere que, após a remoção de $K$ prédios, restem os prédios $Y_1, Y_2, \ldots, Y_{N - K}$. Suponha
que, dentre ele, o prédio $Y_a$ seja o mais próximo do início da avenida e que $Y_b$ seja o mais distante. Neste cenário, a distância entre
o primeiro e o último, que deve ser minimizada, será dada por $Y_b - Y_a$.

Agora, fixe um prédio $X_j$ qualquer. Vamos construir uma remoção de $K$ elementos de tal forma que $X_j$ seja o mais próximo e que a distância entre ele e o último prédio seja a menor possível. Para que isso seja possível, primeiramente devemos remover todos os elementos $X_i$ da sequência tais que $X_i < X_j$ (o texto do problema garante que todos os prédios estão em posições distintas). Se o número de prédios que atendem a esta condição for maior do que $K$, não é possível tal construção.

Se o total de prédio mais próximos da avenida do que $X_j$ for menor ou igual a $K$, então removemos todos eles. Se ainda for necessário remover algum prédio, devemos excluir primeiramente o que estiver mais distante de $X_j$, em seguida o segundo mais distante, e assim por diante. Procedendo desta maneira, restarão apenas $N - K$ prédios e a distância será $X_k - X_j$, onde $X_k$ é o prédio mais distante que não foi removido.

A solução do problema consiste em avaliar todos os elementos, isto é, fazer $j = 1, 2, \ldots, N$ e registrar a menor distância obtida. Esta construção pode ser feita em $O(1)$ se ordenarmos a sequência $X_1, X_2, \ldots, X_N$ em ordem crescente. Daí, para cada $j$, verificar se a posição $k = j + (N - K - 1)$ ainda é válida, isto é, se $k\leq N$. Se $k$ for válido, a distância será $X_k - X_i$.

O custo da ordenação é $O(N\log N)$ e cada um das $N$ verificações custa $O(1)$, de modo que a solução tem complexidade $O(N\log N)$.

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>
#include <stdlib.h>

#define oo 1000000000
#define MAX 100001

int comp(const void* a, const void* b)
{
    return *((int *) a) - *((int *) b);
}

int xs[MAX];

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; ++i)
        scanf("%d", xs + i);

    qsort(xs, N, sizeof(int), comp);

    int ans = oo;

    for (int i = 0, j = N - K - 1; j < N; ++i, ++j)
        if (ans > xs[j] - xs[i])
            ans = xs[j] - xs[i];

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

constexpr int oo { 1'000'000'000 };

auto solve(int N, int K, vector<int>& xs)
{
    sort(xs.begin(), xs.end());

    auto ans = oo;

    for (int i = 0, j = N - K - 1; j < N; ++i, ++j)
        ans = min(ans, xs[j] - xs[i]);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<int> xs(N);

    for (auto& x : xs)
        cin >> x;

    cout << solve(N, K, xs) << '\n';

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em Python</b></summary>

```python
N, K = map(int, input().split())
xs = sorted(map(int, input().split()))
ans = 10**9

for j in range(N - K - 1, N):
    i = j - (N - K - 1)
    ans = min(ans, xs[j] - xs[i])

print(ans)
```
</details>


<details>
    <summary><b>Solução em Java</b></summary>

```java
 import java.util.Arrays;
 import java.util.Scanner;

 public class Main {
     public static void main(String[] args) {
         Scanner scanner = new Scanner(System.in);

         int N = scanner.nextInt();
         int K = scanner.nextInt();

         int xs[] = new int[N];

         for (int i = 0; i < N; ++i)
             xs[i] = scanner.nextInt();


        Arrays.sort(xs);
        int ans = 1000000000;

        for (int j = N - K - 1; j < N; ++j) {
            int i = j - (N - K - 1);
            ans = Math.min(ans, xs[j] - xs[i]);
        }

        System.out.println(ans);
     }
 }
```
</details>
