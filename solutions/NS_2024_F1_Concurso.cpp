// NEPS 2711 - Concurso (https://neps.academy/br/exercise/2711)
#include <bits/stdc++.h>

using namespace std;

auto solve(int K, vector<int>& as)
{
    sort(as.begin(), as.end(), greater<int>());

    return as[K - 1];
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> as(N);

    for (auto& a : as)
        cin >> a;

    cout << solve(K, as) << '\n';

    return 0;
}
