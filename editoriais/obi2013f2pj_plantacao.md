## Plantação

Uma solução que simula a situação descrita no texto, ou seja, a cada dia se atualiza o número de frutas
produzidas por cada árvore, tem complexidade $O(NK)$ e obtém apenas 70 pontos do 100 possíveis.

Para obter a pontuação máxima é preciso observar algumas características do problema. A primeira delas é
que, eventualmente, uma árvore pode deixar de produzir frutas. Suponha que, ao longo dos dias, a primeira
árvore que deixou de produzir frutas foi a árvore $a_{k_1}$; em seguida, a árvore $a_{k_2}$ deixou de
produzir frutas, e assim por diante. O que se pode observar é que a sequência $a_{k_1}, a_{k_2}, \ldots$ é não-decrescente: em outras palavras, as árvores vão deixando de produzir frutas em ordem não-decrescente em
relação ao número de frutas que cada uma produziu no dia anterior ao início da safra.

Inicialmente, são produzidas

$$
F = \sum_{i = 1}^{N} a_i
$$

frutas. Seja $b_1, b_2, \ldots, b_N$ a sequência obtida por meio da ordenação de $a_1, a_2, \ldots, a_N$,
$j = 1$ e $\delta = 0$. A variável $j$ apontará para a árvore que produziu o menor número de frutas no
dia anterior e $\delta$ registrará a variação da produção acumulada ao longo dos dias, de acordo com a 
chuva ou com a estiagem. Inicialize a resposta $R$ com o valor $F$ e, para cada dia, tome as seguintes providências:

1. Atualize o acumulador $\delta$: se choveu, $\delta$ deve ser incrementado; caso contrário, deve ser reduzido em uma unidade.
2. Desconsidere todas as árvores que deixaram de produzir frutas: enquanto $j < N$ e $b_j + \delta = 0$, remova a contribuição de $b_j$ em $F$ (isto é, $F \gets F - b_j$) e incremente $j$.
3. Atualize a resposta $R$, somando a ela a contribuição de todas árvores que ainda produzem frutas $F$, corrigida pela variação $\delta$, ou seja, $R\gets F + (K - j + 1)\delta$.

Esta solução tem complexidade $O(K + N\log N)$.

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100010

int as[MAX];

int comp(const void* x, const void* y)
{
    int a = *((int *) x);
    int b = *((int *) y);

    return a - b;
}

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    long long sum = 0;

    for (int i = 0; i < K; ++i)
    {
        scanf("%d", &as[i]);
        sum += as[i];
    }

    qsort(as, K, sizeof(int), comp);

    long long ans = 0, delta = 0;
    int j = 0;

    for (int i = 0; i < N; ++i)
    {
        char s[2];
        scanf("%s", s);

        delta += s[0] == 'C' ? 1 : -1;

        while (j < K && as[j] + delta == 0)
        {
            sum -= as[j];
            j++;
        }

        ans += sum + (K - j)*delta;
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

auto solve(int K, vector<ll>& as, const string& s)
{
    sort(as.begin(), as.end());

    ll ans = 0, delta = 0, sum = accumulate(as.begin(), as.end(), 0LL);
    int j = 0;

    for (auto c : s)
    {
        delta += c == 'C' ? 1 : -1;

        while (j < K && as[j] + delta == 0)
        {
            sum -= as[j];
            j++;
        }

        ans += sum + (K - j)*delta;
    }

    return ans;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<ll> as(K);

    for (auto& a : as)
        cin >> a;

    string s, t;

    while (N--)
    {
        cin >> t;
        s += t.front();
    }

    cout << solve(K, as, s) << '\n';

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em Python</b></summary>

```Python
N, K = map(int, input().split())
xs = sorted(list(map(int, input().split())), reverse=True)
cs = ''.join(input().split())

ans = 0
delta = 0
s = sum(xs)

for c in cs:
    if c == 'C':
        delta += 1
    else:
        delta -= 1

    while xs and xs[-1] + delta == 0:
        s -= xs[-1]
        xs.pop()

    ans += s + len(xs)*delta

print(ans)
```
</details>


<details>
    <summary><b>Solução em Java</b></summary>

```java
import java.util.Arrays;
import java.util.Scanner;

public class solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int K = scanner.nextInt();

        long sum = 0;
        int[] as = new int[K];

        for (int i = 0; i < K; ++i)
        {
            as[i] = scanner.nextInt();
            sum += as[i];
        }

        Arrays.sort(as);

        long ans = 0, delta = 0;
        int j = 0;

        for (int i = 0; i < N; ++i)
        {
            String s = scanner.next();

            if (s.equals("C")) {
                delta += 1;
            } else {
                delta -= 1;
            }

            while (j < K && as[j] + delta == 0)
            {
                sum -= as[j];
                j++;
            }

            ans += sum + (K - j)*delta;
        }

        System.out.println(ans);
    }
}
```
</details>
