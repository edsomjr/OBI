## Tarzan

Seja $G$ um grafo cujos vértices são as árvores. Há uma aresta entre as árvores $a, b\in V$ se a distância euclidiana entre elas é menor ou
igual a $D$, isto é, $(a, b)\in E$ se, e somente se,

$$
d(a, b) = \sqrt{(a_x - b_x)^2 + (a_y - bỳ)^2} \leq D
$$

Para evitar o uso de aritmética de ponto flutuante, e seus potenciais problemas de precisão, a condição anterior pode ser substituída pela 
condição

$$
d^2(a, b) = (a_x - b_x)^2 + (a_y - bỳ)^2 \leq D^2
$$

Esta segunda condição é equivalente à primeira e pode ser avaliada usando apenas aritmética de números inteiros. A solução do problema consiste
em determinar se $G$ é um grafo conectado ou não. Isso pode ser feito de três maneiras:

1. iniciar uma travessia em profundidade em uma árvore qualquer. Se, ao final da travessia, todas as $N$ árvore forem visitadas, a resposta será '`S`' (ver solução em C);
2. usar a mesma estratégia, substituindo a travessia em profundidade por uma travessia em largura (ver solução em Python);
3. iniciar uma estrutura _union-find_ e, a cada árvore lida na entrada, fazer as uniões com todas as árvores previamente lidas que estejam a 
$D$ unidades ou menos de distância. Se, ao final do processamento da entrada, houver um único componente conectado, a resposta será '`S`' (ver
a solução em C++).

Todas as três soluções possíveis tem complexidade $O(N^2)$, devido ao custo de construção do grafo G.


<details>
    <summary><b>Solução em C</b></summary>

```c
#include <stdio.h>

#define MAX 1010

int adj[MAX][MAX];
int visited[MAX];
int ps[MAX][2];

void dfs(int u)
{
    if (visited[u])
        return;

    visited[u] = 1;

    for (int i = 1; i <= adj[u][0]; ++i)
        dfs(adj[u][i]);
}

char solve(int N)
{
    dfs(0);

    int count = 0;

    for (int u = 0; u < N; ++u)
        count += visited[u];

    return count == N ? 'S' : 'N';
}

int main()
{
    int N, D;
    scanf("%d %d", &N, &D);

    for (int i = 0; i < N; ++i)
    {
        scanf("%d %d", &ps[i][0], &ps[i][1]);

        for (int j = 0; j < i; ++j)
        {
            if ((ps[i][0] - ps[j][0])*(ps[i][0] - ps[j][0]) + (ps[i][1] - ps[j][1])*(ps[i][1] - ps[j][1]) <= D*D)
            {
                adj[i][0]++;
                adj[i][adj[i][0]] = j;

                adj[j][0]++;
                adj[j][adj[j][0]] = i;
            }
        }
    }

    printf("%c\n", solve(N));

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

class UnionFind
{
    vector<int> parent, size;
    int count;

public:
    UnionFind(int N) : parent(N + 1), size(N + 1, 1), count(N)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    bool same_set(int i, int j)
    {
        return find_set(i) == find_set(j);        
    }

    void union_set(int i, int j)
    {
        if (same_set(i, j))
            return;

        int p = find_set(i);
        int q = find_set(j);

        if (size[p] < size[q])
            swap(p, q);

        parent[q] = p;
        size[p] += size[q];
        --count;
    }

    int find_set(int i)
    {
        return parent[i] == i ? i : (parent[i] = find_set(parent[i]));
    }

    int components() const
    {
        return count;
    }
};

auto solve(int N, int D, const vector<ii>& ps)
{
    UnionFind ufds(N);

    for (int u = 0; u < N; ++u)
    {
        auto [ux, uy] = ps[u];

        for (int v = u + 1; v < N; ++v)
        {
            auto [vx, vy] = ps[v];
        
            if ((ux - vx)*(ux - vx) + (uy - vy)*(uy - vy) <= D*D)
                ufds.union_set(u, v);
        }
    }

    return ufds.components() == 1 ? 'S' : 'N';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, D;
    cin >> N >> D;

    vector<ii> ps(N);

    for (auto& [x, y] : ps)
        cin >> x >> y;

    cout << solve(N, D, ps) << '\n';

    return 0;
}
```
</details>


<details>
    <summary><b>Solução em Python</b></summary>

```Python
import queue

def solve(N, adj):
    oo = 10 ** 9 + 7
    dist = [oo] * N

    q = queue.Queue()
    q.put(0)
    dist[0] = 0

    while not q.empty():
        u = q.get()

        for v in adj[u]:
            if dist[v] == oo:
                dist[v] = dist[u] + 1
                q.put(v)

    if sum([1 for x in dist if x < oo]) == N:
        return 'S'
    else:
        return 'N'


if __name__ == '__main__':
    N, D = map(int, input().split())

    ps = []

    for _ in range(N):
        x, y = map(int, input().split())
        ps.append((x, y))

    adj = {}

    for i in range(N):
        adj[i] = []

    for i in range(N):
        for j in range(i + 1, N):
            x, y = ps[i]
            u, v = ps[j]

            if (x - u)**2 + (y - v)**2 <= D**2:
                adj[i].append(j)
                adj[j].append(i)

    print(solve(N, adj))
```
</details>
