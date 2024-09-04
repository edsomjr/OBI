#include <bits/stdc++.h>

using namespace std;

auto solve(int N, const vector<int>& xs)
{
    unordered_set<int> s;
    int L = 0, R = 0, ans = 0;

    while (L < N)
    {
        while (R < N && s.count(xs[R]) == 0)
        {
            s.emplace(xs[R]);
            ++R;
        }

        ans = max(ans, R - L);
        s.erase(xs[L]);
        ++L;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, S;
    cin >> N >> S;

    vector<int> xs(N);

    for (auto& x : xs)
        cin >> x;

    cout << solve(N, xs) << '\n';

    return 0;
}
