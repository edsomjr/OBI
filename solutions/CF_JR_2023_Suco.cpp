#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

auto solve(const vector<ii>& xs)
{
    auto ans = 0;

    for (auto [A, B] : xs)
        ans += (A or not B) ? 1 : 0;

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<ii> xs(N);

    for (auto& [A, B] : xs)
        cin >> A >> B;

    cout << solve(xs) << '\n';

    return 0;
}
