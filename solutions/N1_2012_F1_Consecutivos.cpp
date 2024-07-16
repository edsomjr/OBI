// NEPS 110 - Consecutivos (https://neps.academy/br/exercise/110)
#include <bits/stdc++.h>

using namespace std;

auto solve(int N, const vector<int>& vs)
{
   int ans = 0, L = 0;

    while (L < N)
    {
        int R = L + 1;

        while (R < N && vs[R] == vs[L])
            ++R;

        ans = max(ans, R - L);
        L = R;
    }
    
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> vs(N);

    for (auto& v : vs)
        cin >> v;

    cout << solve(N, vs) << '\n';

    return 0;
}
