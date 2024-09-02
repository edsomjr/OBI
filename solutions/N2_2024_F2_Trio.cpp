#include <bits/stdc++.h>

using namespace std;

auto solve(int N, vector<int>& as)
{
    sort(as.begin(), as.end());

    auto ans = 0;

    for (int i = 1; i < N; ++i) 
        for (int j = 0; j < i; ++j) 
        {
            auto k = static_cast<int>(lower_bound(as.begin(), as.end(), as[i] + as[j]) - as.begin());
            ans += (k - (i + 1));
        }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    vector<int> as(N);

    for (auto& a : as)
        cin >> a;

    cout << solve(N, as) << '\n';

    return 0;
}

