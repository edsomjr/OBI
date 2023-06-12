// OBI 2023 - Fase 1 - Nível 1: VAR (https://olimpiada.ic.unicamp.br/static/extras/obi2023/provas/ProvaOBI2023_f1p1.pdf)
#include <bits/stdc++.h>

using namespace std;

char solve(int X, int Y)
{
    return abs(X) <= 8 and 0 <= Y and Y <= 8 ? 'S' : 'N';
}

int main()
{
    int X, Y;
    cin >> X >> Y;

    cout << solve(X, Y) << '\n';

    return 0;
}
