// NEPS 2438 - Intervalo Distinto (https://neps.academy/br/exercise/2438)
#include <bits/stdc++.h>

using namespace std;

auto solve(int N, const vector<int>& is)
{
    vector<int> found(100'001, 0);

    int ans = 0, L = 0, R = 0;

    while (L < N)
    {
        while (R < N && found[is[R]] == 0)
        {
            found[is[R]] = 1;
            ++R;
        }

        ans = max(ans, R - L);

        found[is[L]] = 0;
        ++L;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> is(N);

    for (auto& i : is)
        cin >> i;

    cout << solve(N, is) << '\n';

    return 0;
}
