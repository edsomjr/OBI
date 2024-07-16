// NEPS 2072 - Chuva (https://neps.academy/br/exercise/2072)
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int N, S;
    cin >> N >> S;

    vector<int> xs(N + 1);

    for (int i = 1; i <= N; ++i)
        cin >> xs[i];

    vector<int> ps(N + 1, 0);

    for (int i = 1; i <= N; ++i)
        ps[i] = ps[i - 1] + xs[i]; 

    vector<int> hist(1'000'001, 0);
    hist[0] = 1;

    long long ans = 0;

    for (int b = 1; b <= N; ++b)
    {
        if (ps[b] >= S)
            ans += hist[ps[b] - S];

        hist[ps[b]]++;
    }

    cout << ans << '\n';

    return 0;
}
