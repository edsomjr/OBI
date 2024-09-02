#include <bits/stdc++.h>

using namespace std;

constexpr int oo { 1'000'000'010 };

auto solve(int N)
{
    vector<int> ans(N + 1, oo);
    ans[0] = 0;

    for (int i = 1; i <= N; ++i)
    {
        auto x = i;

        while (x)
        {
            int d = x % 10;
            x /= 10;

            if (d > 0)
                ans[i] = min(ans[i], ans[i - d] + 1);
        }
    }

    return ans[N];
}

int main()
{
    int N;
    cin >> N;

    cout << solve(N) << '\n';

    return 0;
}
        
