#include <bits/stdc++.h>

using namespace std;

auto solve(int X)
{
    vector<int> ans { 0, 1, 2, 4, 5, 7, 13 };

    return X <= 6 ? ans[X] : 13 + (X - 6) * 6;
}

int main()
{
    int X;
    cin >> X;

    cout << solve(X) << '\n';

    return 0;
}
