// OBI 2016 - Nível Sênior - Fase 2: Times (https://olimpiada.ic.unicamp.br/pratique/ps/2016/f2/times/)
#include <bits/stdc++.h>

using namespace std;

const int MAX { 100'010 };

vector<int> adj[MAX];

pair<vector<int>, vector<int>> solve(int N)
{
    vector<int> where(N + 1, -1);

    queue<int> q;
    q.emplace(1);
    where[1] = 0;

    while (not q.empty())
    {
        auto u = q.front();
        q.pop();

        for (auto x : adj[u])
        {
            if (where[x] == -1)
            {
                where[x] = 1 - where[u];
                q.emplace(x);
            }
        }
    }

    vector<int> A, B;

    for (int u = 1; u <= N; ++u)
        where[u] == 0 ? A.emplace_back(u) : B.emplace_back(u);


    return { A, B };
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int u = 1; u <= N; ++u)
    {
        int M;
        cin >> M;

        while (M--)
        {
            int X;
            cin >> X;

            adj[u].emplace_back(X);
            adj[X].emplace_back(u);
        }
    }

    auto [A, B] = solve(N);

    for (size_t i = 0; i < A.size(); ++i)
        cout << A[i] << (i + 1 == A.size() ? '\n' : ' ');

    for (size_t i = 0; i < B.size(); ++i)
        cout << B[i] << (i + 1 == B.size() ? '\n' : ' ');

    return 0;
}
