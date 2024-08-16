// NEPS 2434 - Pizza da OBI (https://neps.academy/br/exercise/2434)
#include <bits/stdc++.h>

using namespace std;

int solve(int N, int G, int M)
{
    return max(0, 8*G + 6*M - N);
}

int main()
{
    int N, G, M;
    cin >> N >> G >> M;

    cout << solve(N, G, M) << '\n';

    return 0;
}
