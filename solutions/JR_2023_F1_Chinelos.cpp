// NEPS 2317 - Chinelos (https://neps.academy/br/exercise/2317)
#include <bits/stdc++.h>

using namespace std;

auto solve(vector<int>& xs, const vector<int>& ps)
{
    auto ans = 0;

    for (auto p : ps)
        ans += xs[p] > 0 ? --xs[p], 1 : 0;

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> xs(N + 1);

    for (int i = 1; i <= N; ++i)
        cin >> xs[i];

    int P;
    cin >> P;

    vector<int> ps(P);

    for (auto& p : ps)
        cin >> p;

    cout << solve(xs, ps) << '\n';

    return 0;
}
