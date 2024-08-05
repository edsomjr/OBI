// NEPS 2318: VAR (https://neps.academy/br/exercise/2318)
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
