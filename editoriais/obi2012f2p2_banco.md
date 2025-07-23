## Banco

Há duas soluções possíveis para este problema. A primeira delas consiste em manter um vetor $c$, onde
$c(i)$ indica o instante em que o caixa $i$ estará pronto para o próximo atendimento. Inicialmente,
$c(i) = 0$ para todo $i = 1, 2, \ldots, C$.

Agora, para cada cliente $j$ na fila, deve-se procurar o caixa $k$ tal que
$$
c(k) = \min\lbrace c(1), c(2), \ldots, c(C)\rbrace
$$
Este caixa atenderá este cliente no instante $t = \max(c(k), T_j)$. Se $c(k) - T_j > 20$, isto significa
que o cliente esperou 20 minutos ou mais, fato que deve ser contabilizado na resposta. Assim que iniciar o atendimento do cliente $j$, o caixa $k$ só tornará a ficar livre no instante $c(k) = t + T_j$. 

A resposta será o número de clientes que esperaram 20 minutos ou mais antes de serem atendidos. Esta solução tem complexidade $O(NC)$ (veja a solução em C).

Em linguagem que tem, em sua biblioteca padrão, suporte para _heaps_, é possível instanciar uma _min heap_ para armazenar os instantes que os caixas estarão livres. Isto permite identificar qual é o próximo caixa livre em $O(\log C)$, o que leva a uma solução $O(N\log(C))$ (veja a solução em C++).

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int C, N;
    scanf("%d %d", &C, &N);

    int cs[C];

    for (int i = 0; i < C; ++i)
        cs[i] = 0;

    int ans = 0;

    for (int i = 0; i < N; ++i)
    {
        int T, D;
        scanf("%d %d", &T, &D);

        int c = 0, t = cs[c];

        for (int j = 1; j < C; ++j)
            if (cs[j] < cs[c])
            {
                t = cs[j];
                c = j;
            }

        ans += t - T > 20;
        cs[c] = max(t, T) + D;
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
using ii = pair<int, int>;

auto solve(size_t C, vector<ii>& xs)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    auto ans = 0;

    for (auto [T, D] : xs)
    {
        if (pq.size() < C)
        {
            pq.push(T + D);
        } else
        {
            auto t = pq.top();
            pq.pop();

            ans += t - T > 20;
            pq.push(max(t, T) + D);
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int C, N;
    cin >> C >> N;

    vector<ii> xs(N);

    for (auto& [T, D] : xs)
        cin >> T >> D;

    cout << solve(C, xs) << '\n';

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em Python</b></summary>

```python
from heapq import heappop, heappush, heapify

C, N = map(int, input().split())

h = []
heapify(h)

ans = 0

for _ in range(N):
    T, D = map(int, input().split())

    if len(h) < C:
        heappush(h, T + D)
    else:
        t = heappop(h)

        if t - T > 20:
            ans += 1

        heappush(h, max(t, T) + D)

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

        int C = scanner.nextInt();
        int N = scanner.nextInt();

        int[] cs = new int[C];

        for (int i = 0; i < C; ++i) {
            cs[i] = 0;
        }

        int ans = 0;

        for (int i = 0; i < N; ++i) {
            int T = scanner.nextInt();
            int D = scanner.nextInt();

            int c = 0, t = cs[c];

            for (int j = 1; j < C; ++j) {
                if (cs[j] < cs[c]) {
                    t = cs[j];
                    c = j;
                }
            }

            if (t - T > 20) {
                ans += 1;
            }

            cs[c] = Math.max(t, T) + D;
        }

        System.out.println(ans);
    }
}
```
</details>
