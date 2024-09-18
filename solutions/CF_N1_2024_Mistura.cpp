#include <bits/stdc++.h>

using namespace std;
using ll = long long;

auto solve(int N, size_t K, const vector<int>& as)
{
    map<int, int> hist;
    ll ans = 0;
    int R = 0;

    for (int L = 0; L < N; ++L)
    {
        while (R < N && hist.size() < K)
        {
            hist[as[R]]++;
            R++;
        } 

        if (hist.size() == K)
            ans += (N - R) + 1;

        hist[as[L]]--;

        if (hist[as[L]] == 0)
            hist.erase(as[L]);
    }

    return ans;
}


int main()
{
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<int> as(N);

    for (auto& a : as)
        cin >> a;

    cout << solve(N, K, as) << '\n';

    return 0;
}
