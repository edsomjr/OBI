## Tiro ao Alvo

Há duas possíveis soluções para este problema. A primeira delas consiste em um algoritmo _online_ que, para cada tiro, identifica sua pontuação antes de avaliar o próximo tiro. Os raios dos círculos já são informados na entrada em ordem crescente, mas para evitar o uso de variáveis em ponto flutuante, é preciso pré-processar a sequência de raios $r_k$ para obter uma nova sequência $s_k$ tal que $s_k = r_k^2$. 

Agora, se o tiro atingiu o ponto $(x, y)$, sua pontuação pode ser obtida por meio de uma busca binária do valor $x^2 + y^2$ na sequência $s_k$. Se $j$ é o índice do menor elemento de $s_k$ tal que $s_j \geq x^2 + y^2$, então este tiro vale $C - j - 1$ pontos. São $O(T)$ tiros, e cada um pode ser processado em $O(\log C)$, então esta solução em complexidade $O(T\log C)$. Ela está implementada no código C++ abaixo.

Uma segunda solução pode ser obtida por meio de um algoritmo _offline_ no qual os tiros serão pré-processados, todos de uma vez, e as pontuações serão obtidas em ordem distinta da entrada. Além da geração da sequência $s_k$, é preciso gerar uma sequência $d_k$, em ordem não-decrescente, das distâncias ao quadrado de cada tiro em relação à origem, isto é, para cada $j = 1, 2, \ldots, T$, existe um $i\in [1, T]$ tal que
$d_j = x_i^2 + y_i^2$. Agora, para cada elemento da sequência $d_k$, ele deve ser confrontado com o próximo elemento de $s_k$ ainda não removido:

1. se $d_i \leq s_j$, então o tiro cuja distância ao quadrado em relação à origem é $d_i$ vale $|s_k|$ pontos - avance para o próximo elemento de $d_k$;
2. caso contrário, remova $s_j$ da sequência $s_k$ e reavalie $d_i$.

A ordenação da sequência $d_k$ pode ser feita em $O(T\log T)$ e o processamento dos tiros tem complexidade $O(T + C)$, portanto esta solução tem complexidade $O(C + T\log T)$. Ele está implementada no código C abaixo.

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    const long long *x = (const long long *) a, *y = (const long long *) b;

    if (*x < *y)
        return -1;
    else if (*x > *y)
        return 1;
    else
        return 0;
}

int main()
{
    int C, T;
    scanf("%d %d", &C, &T);

    long long rs[C];

    for (int i = 0; i < C; ++i)
    {
        long long r;
        scanf("%lld", &r);

        rs[i] = r*r;
    }

    long long ds[T];

    for (int i = 0; i < T; ++i)
    {
        long long x, y;
        scanf("%lld %lld", &x, &y);

        ds[i] = x*x + y*y;
    }

    qsort(ds, T, sizeof(long long), compare);

    long long ans = 0;
    int j = 0;

    for (int i = 0; i < T; ++i)
    {
        while (j < C && rs[j] < ds[i])
            ++j;
        
        ans += (C - j);
    }

    printf("%lld\n", ans);

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em C++</b></summary>

```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

auto solve(int C, const vector<ll>& rs, const vector<ii>& ts)
{
    ll ans = 0;

    for (auto [x, y] : ts)
    {
        auto it = lower_bound(rs.begin(), rs.end(), x*x + y*y);
        ans += C - (it - rs.begin());
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int C, T;
    cin >> C >> T;

    vector<ll> rs(C);

    for (auto& r : rs)
    {
        cin >> r;
        r *= r;
    }

    vector<ii> ts(T);

    for (auto& [x, y] : ts)
        cin >> x >> y;

    cout << solve(C, rs, ts) << '\n';

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em Python</b></summary>

```Python
C, T = map(int, input().split())

rs = []

for _ in range(C):
    rs.append(int(input()))

rs = [x**2 for x in rs[::-1]]
ts = []

for _ in range(T):
    x, y = map(int, input().split())
    ts.append(x**2 + y**2)

ans = 0

for t in sorted(ts):
    while rs and rs[-1] < t:
        rs.pop()

    ans += len(rs)

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

        int C = scanner.nextInt();
        int T = scanner.nextInt();

        long[] rs = new long[C];

        for (int i = 0; i < C; ++i) {
            long r = scanner.nextLong();
            rs[i] = r*r;
        }

        long[] ts = new long[T];

        for (int i = 0; i < T; ++i) {
            long x = scanner.nextLong();
            long y = scanner.nextLong();
            ts[i] = x*x + y*y;
        }

        Arrays.sort(ts);
        long ans = 0;
        int j = 0;

        for (int i = 0; i < T; ++i) {
            while (j < C && rs[j] < ts[i])
                j += 1;

            ans += C - j;
        }

        System.out.println(ans);
    }
}
```
</details>
