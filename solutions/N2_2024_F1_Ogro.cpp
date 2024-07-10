// NEPS 2710 - Ogro (https://neps.academy/br/exercise/2710)
#include <bits/stdc++.h>

using namespace std;

auto solve(int E, int D)
{
    return E > D ? E + D : 2*(D - E);
}

int main()
{
    int E, D;
    cin >> E >> D;

    cout << solve(E, D) << '\n';

    return 0;
}
