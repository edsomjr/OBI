// OBI 2019 - Nível Sênior - Fase 1: Soma (https://olimpiada.ic.unicamp.br/pratique/pu/2019/f1/soma/)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

auto solve(const vector<int>& xs, int K)
{
    map<int, int> ms;
    int sum = 0;
    ll ans = 0;

    for (auto x : xs)
    {
        sum += x;

        if (sum == K)
            ++ans;

        auto diff = sum - K;
        ans += (ms.count(diff) ? ms[diff] : 0);

        ++ms[sum];
    }
        
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    cout << solve(xs, K) << '\n';

    return 0;
}
