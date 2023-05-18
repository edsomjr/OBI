// OBI 2021 - Nível 2 - Fase 1: Idade de Camila (https://olimpiada.ic.unicamp.br/pratique/p2/2021/f1/idade/)
#include <bits/stdc++.h>

using namespace std;

auto solve(int a, int b, int c)
{
    return a + b + c - min({a, b, c}) - max({a, b, c});
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    cout << solve(a, b, c) << '\n';

    return 0;
}
