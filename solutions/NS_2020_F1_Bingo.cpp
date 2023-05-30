// OBI 2020 - Nível Sênior - Fase 1: Bingo! (https://olimpiada.ic.unicamp.br/pratique/ps/2020/f1/bingo/)
#include <bits/stdc++.h>

using namespace std;

const int MAX { 10'110 };

vector<int> adj[MAX];

auto solve(int N, int K, const vector<int>& xs)
{
    vector<int> ans, cs(N + 1, K);

    for (auto x : xs)
    {
        for (auto y : adj[x])
        {
            --cs[y];

            if (cs[y] == 0)
                ans.emplace_back(y);
        }

        if (not ans.empty())
            break;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, U;
    cin >> N >> K >> U;

    for (int i = 1; i <= N; ++i)
        for (int k = 0; k < K; ++k)
        {
            int x;
            cin >> x;

            adj[x].emplace_back(i);
        }

    vector<int> xs(U);

    for (int i = 0; i < U; ++i)
        cin >> xs[i];

    auto ans = solve(N, K, xs);

    for (size_t i = 0; i < ans.size(); ++i)
        cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
    
    return 0;
}
