// OBI 2019 - Nível Sênior - Fase 1: A idade de Dona Mônica (https://olimpiada.ic.unicamp.br/pratique/pu/2019/f1/idade/)
#include <bits/stdc++.h>

using namespace std;

int solve(int M, int A, int B)
{
    int C = M - A - B;

    return max(max(A, B), C);
}

int main()
{
    int M, A, B;
    cin >> M >> A >> B;

    auto ans = solve(M, A, B);

    cout << ans << '\n';

    return 0;
}
