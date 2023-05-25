// OBI 2019 - Nível Sênior - Fase 1: Calçada Imperial (https://olimpiada.ic.unicamp.br/pratique/pu/2019/f1/imperial/)
#include <bits/stdc++.h>

using namespace std;

const int oo { 1'000'000'000 };

auto solve(int N, const vector<int>& xs)
{
    map<int, vector<int>> is;

    for (int i = 0; i < N; ++i)
        is[xs[i]].emplace_back(i);

    int ans = 1;

    for (int a = 1; a <= N; ++a)
    {
        for (int b = a + 1; b <= N; ++b)
        {
            size_t L = 0, R = 0;
            int count = 0, last = -1;
            
            while (L < is[a].size() or R < is[b].size())
            {
                auto x = L == is[a].size() ? oo : is[a][L];
                auto y = R == is[b].size() ? oo : is[b][R];

                if (x < y)
                {
                    count += (last != 0 ? 1 : 0);
                    ++L;
                    last = 0;
                } else
                {
                    count += (last != 1 ? 1 : 0);
                    ++R;
                    last = 1;
                }
            } 

            ans = max(ans, count);
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    cout << solve(N, xs) << '\n';

    return 0;
}
