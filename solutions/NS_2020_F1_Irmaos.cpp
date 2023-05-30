// OBI 2020 - Nível Sênior - Fase 1: Irmãos (https://olimpiada.ic.unicamp.br/pratique/ps/2020/f1/irmaos/)
#include <bits/stdc++.h>

using namespace std;

int solve(int N, int M)
{
    return 2*M - N;
}

int main()
{
    int N, M;
    cin >> N >> M;

    cout << solve(N, M) << '\n';

    return 0;
}
