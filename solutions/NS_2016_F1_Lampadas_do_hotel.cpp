// OBI 2023 - Nível Sênior - Fase 1: Lâmpadas do hotel (https://olimpiada.ic.unicamp.br/pratique/ps/2016/f1/lampadas-hotel/)
#include <bits/stdc++.h>

using namespace std;

const int oo { 1'000'000'000 };

int solve(int Ia, int Ib, int Fa, int Fb)
{
    int states[2][2] { oo, oo, oo, oo };
    states[Ia][Ib] = 0;

    using ii = pair<int, int>;

    queue<ii> q;
    q.push(ii(Ia, Ib));

    while (not q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        // Lâmpada A
        auto a = 1 - x, b = y;

        if (states[a][b] == oo)
        {
            states[a][b] = states[x][y] + 1;
            q.push(ii(a, b));
        }

        // Lâmpada B
        auto c = 1 - x, d = 1 - y;

        if (states[c][d] == oo)
        {
            states[c][d] = states[x][y] + 1;
            q.push(ii(c, d));
        }
    }

    return states[Fa][Fb];
}

int main()
{
    int Ia, Ib, Fa, Fb;
    cin >> Ia >> Ib >> Fa >> Fb;

    cout << solve(Ia, Ib, Fa, Fb) << '\n';

    return 0;
}
