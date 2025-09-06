## Feirinha de Artesanato

Uma possível solução para o problema consiste na criação de dois vetores auxiliares $t_1$ e $t_2$, que
conterão os preços dos itens dos tipos 1 e 2, respectivamente. Uma vez ordenados que ambos vetores estejam em ordem crescente, é
possível simular o comportamento dos clientes mediante três critérios, onde a variável $t$ indica o tipo
do cliente:

1. se $t = 1$ ou se $t = 0$ e não há mais itens do tipo 2 disponíveis, o cliente adquirirá o item do tipo 1 mais barato ainda disponível, caso exista;
1. de forma análoga, se $t = 2$ ou se $t = 0$ e não há mais itens do tipo 1 disponíveis, o cliente adquirirá o item do tipo 2 mais barato ainda disponível, caso exista;
1. caso contrário, o cliente levará o item mais barato disponível, independente do tipo.

A resposta será o total dos custos dos itens adquiridos. Esta solução tem complexidade $O(C\log N)$, devido o custo da ordenação.

<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100010

int ts[MAX], ps[MAX], t1[MAX], t2[MAX];

int compare(const void* p, const void* q)
{
    int x = *((int *) p), y = *((int *) q);
    return x - y;
}

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; ++i)
        scanf("%d", &ts[i]);

    for (int i = 0; i < N; ++i)
        scanf("%d", &ps[i]);

    int a = 0, b = 0;

    for (int i = 0; i < N; ++i)
    {
        if (ts[i] == 1)
            t1[a++] = ps[i];
        else
            t2[b++] = ps[i];
    }

    qsort(t1, a, sizeof(int), compare);
    qsort(t2, b, sizeof(int), compare);

    int C;
    scanf("%d", &C);

    int ans = 0, i = 0, j = 0;

    while (C--)
    {
        int t;
        scanf("%d", &t);

        if (t == 1 || (t == 0 && j == b))
            ans += (i < a ? t1[i++] : 0);
        else if (t == 2 || (t == 0 && i == a))
            ans += (j < b ? t2[j++] : 0);
        else
            ans += (t1[i] <= t2[j] ? t1[i++] : t2[j++]);
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

constexpr int oo { 2'000'000'010 };

auto solve(const vector<int>& ts, const vector<int>& ps, const vector<int>& cs)
{
    priority_queue<int, vector<int>, greater<int>> pq[3];
    pq[1].emplace(oo);
    pq[2].emplace(oo);

    for (size_t i = 0; i < ts.size(); ++i)
        pq[ts[i]].emplace(ps[i]);

    auto ans = 0;

    for (auto c : cs)
    {
        c = c > 0 ? c : 2 - (pq[1].top() <= pq[2].top());

        if (pq[c].top() != oo)
        {
            ans += pq[c].top();
            pq[c].pop();
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> ts(N), ps(N);

    for (auto& t : ts)
        cin >> t;

    for (auto& p : ps)
        cin >> p;

    int C;
    cin >> C;

    vector<int> cs(C);

    for (auto& c : cs)
        cin >> c;

    cout << solve(ts, ps, cs) << '\n';

    return 0;
}
```
</details>

<details>
    <summary><b>Solução em Python</b></summary>

```Python
N = int(input())
ts = map(int, input().split())
ps = map(int, input().split())
C = int(input())
cs = map(int, input().split())
oo = 2 ** 60

xs = [ [], [oo], [oo] ]

for t, p in zip(ts, ps):
    xs[t].append(p)

xs[1].sort(reverse=True)
xs[2].sort(reverse=True)

ans = 0

for c in cs:
    if c == 0:
        if xs[1][-1] <= xs[2][-1]:
            c = 1
        else:
            c = 2

    if xs[c][-1] != oo:
        ans += xs[c][-1]
        xs[c].pop()

print(ans)
```
</details>
