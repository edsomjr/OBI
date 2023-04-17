// OB1 2015 - Nível Sênior - Fase 1: Metrô (https://olimpiada.ic.unicamp.br/pratique/pu/2015/f1/metro/) 
#include <bits/stdc++.h>

using namespace std;

const int MAX { 20010 };

vector<int> adj[MAX];
bitset<MAX> found;

int dfs(int u)
{
    if (found[u])
        return 0;

    found[u] = true;

    int res = 1;

    for (auto v : adj[u])
        if (adj[v].size() <= 2ul)
            res += dfs(v);

    return res;
}

int solve(int N)
{
    int root = 0;
    vector<int> fs;

    for (int u = 1; u <= N; ++u)
    {
        int s = (int) adj[u].size();

        if (s >= 5)
            root = u;
        else if (s == 1)
            fs.push_back(u);
    }

    int ans = N;

    for (auto u : fs)
        ans -= dfs(u);

    ans -= dfs(root);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    while (M--)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto ans = solve(N);

    cout << ans << '\n';

    return 0;
}
