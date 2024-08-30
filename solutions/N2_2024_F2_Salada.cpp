#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

auto solve(int R, const vector<ii>& xs)
{
    priority_queue<ii, vector<ii>, greater<ii>> pq { xs.begin(), xs.end() };
    set<int> s;
    auto ans = 0;
 
    while (not pq.empty())
    {
        auto [P, T] = pq.top();
        pq.pop();

        if (s.count(T))
            continue;

        s.emplace(T);

        if (R < P)
            break;

        ++ans;
        R -= P;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int R, N;
    cin >> R >> N;

    vector<ii> xs(N);

    for (auto& [P, T] : xs)
        cin >> T >> P;

    cout << solve(R, xs) << '\n';

    return 0;
}
