// OBI 2023 - Fase 1 - Nível Sênior: Sr. Toupeira (https://olimpiada.ic.unicamp.br/static/extras/obi2023/provas/ProvaOBI2023_f1ps.pdf)
#include <bits/stdc++.h>

using namespace std;

const int MAX { 1'010 };

int adj[MAX][MAX];

int solve(const vector<vector<int>>& ps)
{
    int ans = 0;

    for (auto xs : ps)
    {
        int ok = 1, now = xs.front();

        for (size_t i = 1; i < xs.size(); ++i)
        {
            if (not adj[now][xs[i]])
            {
                ok = 0;
                break;
            }

            now = xs[i];
        }

        ans += ok;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int S, T;
    cin >> S >> T;

    while (T--)
    {
        int x, y;
        cin >> x >> y;

        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    int P;
    cin >> P;

    vector<vector<int>> ps;

    while (P--)
    {
        int N;
        cin >> N;

        vector<int> xs(N);

        for (int i = 0; i < N; ++i)
            cin >> xs[i];

        ps.emplace_back(xs);
    }

    cout << solve(ps) << '\n';

    return 0;
}
