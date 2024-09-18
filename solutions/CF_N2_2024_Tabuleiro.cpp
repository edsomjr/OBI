#include <bits/stdc++.h>

using namespace std;

constexpr int MOD { 1'000'000'007 };

auto solve(int N)
{
    vector<unsigned int> ways(N + 1, 1);

    if (N >= 2)
        ways[2] = 3;

     for (int i = 3; i <= N; ++i)
    {
        ways[i] = (ways[i - 1] + 2*ways[i - 2]) % MOD;
        ways[i] = (ways[i] + 2*ways[i - 3]) % MOD;
    }

    return ways[N];
}

int main()
{
    int N;
    cin >> N;

    cout << solve(N) << '\n';

    return 0;
}
