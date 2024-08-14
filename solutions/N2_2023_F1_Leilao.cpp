// NEPS 2322 - Leilão (https://neps.academy/br/exercise/2322)
#include <bits/stdc++.h>

using namespace std;
using si = pair<string, int>;

si solve(const vector<si>& xs)
{
    int ans = 0;
    string name;

    for (auto [C, V] : xs)
    {
        if (V > ans)
        {
            ans = V;
            name = C;
        }
    }

    return { name, ans };
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<si> xs(N);

    for (int i = 0; i < N; ++i)
            cin >> xs[i].first >> xs[i].second;

    auto [name, ans] = solve(xs);

    cout << name << '\n';
    cout << ans << '\n';

    return 0;
}
