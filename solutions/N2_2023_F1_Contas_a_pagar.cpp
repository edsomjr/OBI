// OBI 2023 - Fase 1 - Nível 2: Contas a pagar (https://olimpiada.ic.unicamp.br/static/extras/obi2023/provas/ProvaOBI2023_f1p2.pdf)
#include <bits/stdc++.h>

using namespace std;

int solve(int V, int A, int F, int P)
{
    auto S = A + F + P;

    if (V >= S)
        return 3;
    else if (V >= A + F or V >= A + P or V >= F + P)
        return 2;
    else if (V >= A or V >= F or V >= P)
        return 1;

    return 0;
}

int main()
{
    int V, A, F, P;
    cin >> V >> A >> F >> P;

    cout << solve(V, A, F, P) << '\n';

    return 0;
}
