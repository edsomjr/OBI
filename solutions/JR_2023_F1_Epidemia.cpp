// NEPS 2316 - Epidemia (https://neps.academy/br/exercise/2316)
#include <bits/stdc++.h>

using namespace std;

auto solve(int N, int R, int P)
{
    auto total = N, ans = 0;

    while (total < P)
    {
        N *= R;
        total += N;
        ++ans;
    }

    return ans;
}

int main()
{
    int N, R, P;
    cin >> N >> R >> P;

    cout << solve(N, R, P) << '\n';

    return 0;
}
