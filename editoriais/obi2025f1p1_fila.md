## Fila

Assuma inicialmente que, exceto pelo aluno que ocupa a posição $N$, todos os $N - 1$ restantes
poderiam colar.
Para retirar destes o que não poderão colar, por estarem na linha de visão do professor, podemos
proceder da seguinte maneira: seja $H_i$ a maior altura entre todos os estudantes que se sentaram,
em relação ao professor, à frente do estudante $i$. Então o estudante $i$ não poderá colar se 
$i > H_i$. 

Fazendo $H_N = a_N$, os valores de $H_i$ podem ser computados a por meio de uma recorrência: 
$H_i = \max(H_{i + 1}, a_{i + 1})$, ou seja, $H_i$ é igual a $H_{i + 1}$, se o aluno $i + 1$ tem altura
menor ou igual a $H_{i + 1}$ (que é a maior altura possível entre os colegas que estão à frente dele),
ou será igual à altura do estudante $i + 1$.

Assim, partindo do estudante $N$ e atualizando os valores de $H_i$ a cada iteração, o problema pode
ser resolvido em $O(N)$.

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>

#define MAX 100010

int xs[MAX];

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; ++i)
        scanf("%d", xs + i);

    int ans = N - 1, max = xs[N - 1];

    for (int i = N - 2; i >= 0; --i)
    {
        if (xs[i] > max)
        {
            --ans;
            max = xs[i];
        }
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

auto solve(int N, vector<int>& xs)
{
    reverse(xs.begin(), xs.end());

    auto ans = N, h = 0;

    for (auto x : xs)
    {
        ans -= x > h ? 1 : 0;
        h = max(h, x);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> xs(N);

    for (auto& x : xs)
        cin >> x;

    cout << solve(N, xs) << '\n';

    return 0;
}
```
</details>

<details>
    <summary><b>Solução em Python</b></summary>

```Python
N = int(input())
hs = list(map(int, input().split()))[::-1]

ans = N
best = 0

for h in hs:
    if h > best:
        ans -= 1
        best = h

print(ans)
```
</details>

<details>
    <summary><b>Solução em Java</b></summary>

```Java
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.Arrays;

public class solution {
    public static void main(String[] args) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int N = 0;
        int[] xs = null;

        try {
            String line = reader.readLine();
            N = Integer.parseInt(line);

            line = reader.readLine();
            xs = Arrays.stream(line.split(" "))
                             .mapToInt(Integer::parseInt)
                             .toArray();
        } catch (Exception ex) {
        }

        int ans = N - 1, h = xs[N - 1];

        for (int i = N - 2; i >= 0; --i) {
            if (xs[i] > h) {
                h = xs[i];
                ans -= 1;
            }
        }

        System.out.println(ans);
    }
}
```
</details>
