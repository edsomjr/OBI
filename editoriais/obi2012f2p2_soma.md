## Soma das casas

Dado o valor máximo de $N$, uma solução que, para cada casa $i$, avaliasse a soma $C_i + C_j$ para todo
$j\in [i + 1,N]$ teria complexidade $O(N^2)$ e veredito TLE.

O texto do problema nos garante que $C_i < C_j$ se $i < j$, ou seja, os números das casas estão em ordem
crescente. Sejam $L, R$ dois inteiros que indicam, a cada etapa da solução, um par de casas distintas. Assuma que, inicialmente, temos $L = 1$ e $R = N$. Pela tricotomia dos números inteiros temos três cenários possíveis:

1. $C_L + C_R = K$
2. $C_L + C_R < K$
3. $C_L + C_R > K$

No primeiro caso, $A = L$ e $B = R$ é a solução do problema. No segundo caso, como a sequência dos números das casas está em ordem crescente, para aumentar a soma dos números casas indicadas por $L$ e $R$ é preciso incrementar $L$, de modo que ele aponte para a próxima casa à direita, cujo número será maior do que a casa que ele estava apontando. No terceiro cenário, basta decrementar $R$ em uma unidade, para diminuir a soma atual.

Esta solução tem complexidade $O(N)$.

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int cs[N];

    for (int i = 0; i < N; ++i)
        scanf("%d", &cs[i]);

    int K;
    scanf("%d", &K);

    int L = 0, R = N - 1;

    while (L <= R)
    {
        int s = cs[L] + cs[R];

        if (s == K)
        {
            printf("%d %d\n", cs[L], cs[R]);
            return 0;
        } else if (s < K)
            ++L;
        else
            --R;
    }

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em C++</b></summary>

```cpp
#include <bits/stdc++.h>

using namespace std;

auto solve(int N, int K, const vector<int>& cs)
{
    auto L = 0, R = N - 1;

    while (L <= R)
    {
        auto s = cs[L] + cs[R];

        if (s == K)
            return make_pair(cs[L], cs[R]);
        else if (s < K)
            ++L;
        else
            --R;
    }

    return make_pair(-1, -1);
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> cs(N);

    for (auto& c : cs)
        cin >> c;

    int K;
    cin >> K;

    auto [a, b] = solve(N, K, cs);

    cout << a << ' ' << b << '\n';

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em Python</b></summary>

```python
N = int(input())
cs = []

for _ in range(N):
    cs.append(int(input()))

K = int(input())

L = 0
R = N - 1

while L <= R:
    s = cs[L] + cs[R];

    if s == K:
        print(f'{cs[L]} {cs[R]}')
        break
    elif s < K:
        L += 1
    else:
        R -= 1
```
</details>


<details>
    <summary><b>Solução em Java</b></summary>

```java
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class solution {
    public static void main(String[] args) {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = 0, K = 0;
        int cs[] = null;

        try {
            String line = in.readLine();
            N = Integer.parseInt(line);

            cs = new int[N];

            for (int i = 0; i < N; ++i)
            {
                line = in.readLine();
                cs[i] = Integer.parseInt(line);
            }

            line = in.readLine();
            K = Integer.parseInt(line);
        } catch (Exception ex)
        {
        }
        
        int L = 0, R = N - 1;

        while (L <= R)
        {
            int s = cs[L] + cs[R];

            if (s == K)
            {
                System.out.println(Integer.toString(cs[L]) + " " + Integer.toString(cs[R]));
                break;
            } else if (s < K)
                ++L;
            else
                --R;
        }
    }
}
```
</details>
