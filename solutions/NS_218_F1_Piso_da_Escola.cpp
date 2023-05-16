// OBI 2018 - NS F1: Piso da Escola (https://olimpiada.ic.unicamp.br/pratique/ps/2018/f1/piso/)
#include <bits/stdc++.h>

using namespace std;

pair<int, int> solve(int L, int C)
{
    int tipo1 = L*C + (L - 1)*(C - 1);
    int tipo2 = 2*((L - 1) + (C - 1));

    return { tipo1, tipo2 };
}

int main()
{
    int L, C;
    cin >> L >> C;

    auto [x, y] = solve(L, C);

    cout << x << '\n' << y << '\n';

    return 0;
}
