#include <bits/stdc++.h>

using namespace std;
using ll = long long;

auto solve(ll X, ll Y, ll Z, ll N)
{
    return (X + Y + Z) % N;
}

int main()
{
    ll X, Y, Z, N;
    cin >> X >> Y >> Z >> N;

    cout << solve(X, Y, Z, N) << '\n';

    return 0;
}
