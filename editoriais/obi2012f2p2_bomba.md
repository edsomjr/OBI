## Bomba

Seja $G$ o grafo direcionado cujos vértices são as rotatórias e as arestas as ruas. A existência de uma aresta ligando a rotatória $A$ à rotatória $B$ depende do instante $T$ (de fato, do resto da divisão de $T$ por 3) e do tipo de semáforo da rua $AB$.

Como o custo de travessia das ruas é sempre o mesmo (1 minuto), é possível determinar a distância mínima entre $E$ e $S$ por meio de uma travessia de largura (BFS) em $G$. É preciso atentar ao fato de que o ônibus pode chegar à rotatória $S$ nos instantes $t = 0, 1, 2$, de modo que a resposta deve ser a menor entre estas três possibilidades.

Esta solução tem complexidade $O(N + M)$.

<details>
    <summary><b>Solução em C++</b></summary>

```cpp
#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

constexpr int MAX { 510 }, oo { 1'000'000'010 };

vector<ii> adj[MAX];

auto solve(int N, int E, int S)
{
    vector<vector<int>> dist(N, vector<int>(3, oo));

    dist[E][0] = 0;

    queue<ii> q;
    q.emplace(E, 0);

    while (not q.empty())
    {
        auto [u, t] = q.front();
        q.pop();

        auto nxt = (t + 1) % 3;

        for (auto [v, s] : adj[u])
            if (((t == 0 and s == 1) or (t > 0 and s == 0)) and dist[v][nxt] == oo)
            {
                dist[v][nxt] = dist[u][t] + 1;
                q.emplace(v, nxt);
            }
    }

    auto ans = oo;

    for (int t = 0; t < 3; ++t)
        ans = min(ans, dist[S][t]);

    return ans == oo ? "*" : to_string(ans);
}

int main()
{
    ios::sync_with_stdio(false);

    int N, E, S, M;
    cin >> N >> E >> S >> M;

    while (M--)
    {
        int A, B, T;
        cin >> A >> B >> T;

        adj[A].emplace_back(B, T);
    }

    cout << solve(N, E, S) << '\n';

    return 0;
}
```
</details>

<details>
    <summary><b>Solução em Python</b></summary>

```python
N, E, S, M = map(int, input().split())

adj = [[] for _ in range(N)]

for _ in range(M):
    A, B, T = map(int, input().split())
    adj[A].append((B, T))

oo = 2*10**9 + 7

dist = [[oo, oo, oo] for _ in range(N)]
dist[E][0] = 0

import queue
q = queue.SimpleQueue()

q.put((E, 0))

while not q.empty():
    u, t = q.get()
    nxt = (t + 1) % 3

    for v, s in adj[u]:
        if ((t == 0 and s == 1) or (t > 0 and s == 0)) and dist[v][nxt] == oo:
            dist[v][nxt] = dist[u][t] + 1
            q.put((v, nxt))

ans = min(dist[S])

if ans == oo:
    print('*')
else:
    print(ans)
```
</details>
