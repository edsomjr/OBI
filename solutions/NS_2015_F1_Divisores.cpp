// OBI 2015 - Nível Sênior - Fase 1: Divisores (https://olimpiada.ic.unicamp.br/pratique/ps/2015/f1/divisores/)
#include <bits/stdc++.h>

using namespace std;

int solve(int N)
{
    int divisores = 0;

    for (int d = 1; d * d <= N; ++d)
    {
        if (N % d)
            continue;

        auto k = N / d;

        divisores += (d == k ? 1 : 2);
    }

    return divisores;
}

int main()
{
    int N;
    cin >> N;

    cout << solve(N) << '\n';

    return 0;
}
