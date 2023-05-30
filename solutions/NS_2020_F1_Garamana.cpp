// OBI 2020 - Nível Sênior - Fase 1: Garanama (https://olimpiada.ic.unicamp.br/pratique/ps/2020/f1/garamana/)
#include <bits/stdc++.h>

using namespace std;

auto solve(const string& P, const string& A)
{
    vector<int> histP(256, 0), histA(256, 0);

    for (auto c : P)
        ++histP[c];

    for (auto c : A)
        ++histA[c];

    for (int i = 'a'; i <= 'z'; ++i)
    {
        if (histP[i] == 0)
            continue;

        if (histA[i] > histP[i])
            return 'N';

        auto diff = histP[i] - histA[i];

        if (diff > 0 and histA['*'] < diff)
            return 'N';

        histA['*'] -= diff;
        histA[i] = 0;
    }

    return 'S';
}

int main()
{
    string P, A;
    cin >> P >> A;

    cout << solve(P, A) << '\n';

    return 0;
}
