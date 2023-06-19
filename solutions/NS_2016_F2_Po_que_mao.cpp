// OBI 2016 - Nível Sênior - Fase 2: Pô, que mão (https://olimpiada.ic.unicamp.br/pratique/ps/2016/f2/pokemon/)
#include <bits/stdc++.h>

using namespace std;

int solve(int N, int X, int Y, int Z)
{
    set<int> xs { X, Y, Z };
    int ans = 0;

    for (auto x : xs)
        if (x <= N)
        {
            N -= x;
            ++ans;
        }

    return ans;
}

int main()
{
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    cout << solve(N, X, Y, Z) << '\n';

    return 0;
}
