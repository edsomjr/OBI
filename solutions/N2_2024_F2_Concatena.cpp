#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

auto solve(int N, const vector<int>& xs, const vector<ii>& qs)
{
    vector<ll> ps(N + 1, 0);
    partial_sum(xs.begin(), xs.end(), ps.begin() + 1);

    vector<ll> ans;

    for (auto [L, R] : qs)
        ans.emplace_back(11*(R - L)*(ps[R] - ps[L - 1]));

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    vector<int> xs(N);

    for (auto& x : xs)
        cin >> x;

    vector<ii> qs(Q);

    for (auto& [L, R] : qs)
        cin >> L >> R;

    auto ans = solve(N, xs, qs);

    for (auto x : ans)
        cout << x << '\n';

    return 0;
}
