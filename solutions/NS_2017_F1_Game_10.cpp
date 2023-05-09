// OBI 2017 - Nível Sênior - Fase 1: Game 10 (https://olimpiada.ic.unicamp.br/pratique/ps/2017/f1/game10/)
#include <bits/stdc++.h>

using namespace std;

auto solve(int N, int D, int A)
{
    return (D - A + N) % N;
}

int main()
{
    int N, D, A;
    cin >> N >> D >> A;

    cout << solve(N, D, A) << '\n';

    return 0;
}
