// OBI 2014 - Nível Sênior - Fase 2: Voo (https://olimpiada.ic.unicamp.br/pratique/ps/2014/f2/voo/)
#include <bits/stdc++.h>

using namespace std;

const int day = 24*60;

pair<int, int> solve(int p_A, int c_B, int p_B, int c_A)
{
    int fuso, duracao;

    for (fuso = -11; fuso <= 12; ++fuso)
    {
        auto start = p_A + fuso*60;
        auto end = c_B;

        if (start < 0)
            start += day;

        if (start > day)
            start -= day;

        auto x = end - start;

        if (x < 0)
            x += day;

        start = p_B - fuso*60;
        end = c_A;

        if (start < 0)
            start += day;

        if (start > day)
            start -= day;

        auto y = end - start;

        if (y < 0)
            y += day;

        if (x == y and x < day / 2)
        {
            duracao = x;
            break;
        }
    }

    return { duracao, fuso };
}

int main()
{
    int h, m;
    char sep;

    cin >> h >> sep >> m;
    auto p_A = 60*h + m;

    cin >> h >> sep >> m;
    auto c_B = 60*h + m;

    cin >> h >> sep >> m;
    auto p_B = 60*h + m;

    cin >> h >> sep >> m;
    auto c_A = 60*h + m;

    auto [duracao, fuso] = solve(p_A, c_B, p_B, c_A);

    cout << duracao << ' ' << fuso << '\n';

    return 0;
}
