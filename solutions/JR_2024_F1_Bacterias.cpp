// NEPS 2711 - Bactérias (https://neps.academy/br/exercise/2712)
#include <bits/stdc++.h>

using namespace std;

int solve(int N, int P)
{
    int ans = 0, total = 1;

    while (total * P <= N)
    {
        total *= P;
        ans += 1;
    }

    return ans;
}

int main()
{
    int N, P;
    cin >> N >> P;

    cout << solve(N, P) << '\n';

    return 0;
}
