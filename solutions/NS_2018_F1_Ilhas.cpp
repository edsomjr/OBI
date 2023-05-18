// OBI 2018 - Nivel Sênior - Fase 1: Ilhas (https://olimpiada.ic.unicamp.br/pratique/ps/2018/f1/ilhas/)
#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 100'010 }, oo { 1'000'000'010 };

vector<ii> adj[MAX];

vector<int> dijkstra(int N, int S)
{
    vector<int> dist(N + 1, oo);
    dist[S] = 0;

    set<ii> U;
    U.emplace(0, S);

    while (not U.empty())
    {
        auto [d, u] = *U.begin();
        U.erase(U.begin());

        for (auto [v, w] : adj[u])
        {
            if (dist[v] > d + w)
            {
                if (U.count(ii(dist[v], v)))
                    U.erase(ii(dist[v], v));

                dist[v] = d + w;
                U.emplace(dist[v], v);
            }
        }
    }

    return dist;
}

auto solve(int N, int S)
{
    auto dist = dijkstra(N, S);
    auto a = oo, b = -oo;

    for (int u = 1; u <= N; ++u)
    {
        if (u == S)
            continue;

        a = min(a, dist[u]);
        b = max(b, dist[u]);
    }

    return b - a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    while (M--)
    {
        int u, v, p;
        cin >> u >> v >> p;

        adj[u].emplace_back(v, p);
        adj[v].emplace_back(u, p);
    }

    int S;
    cin >> S;

    cout << solve(N, S) << '\n';

    return 0;
}
