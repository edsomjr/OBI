// NEPS: Subsequência (https://neps.academy/br/exercise/2320)
#include <bits/stdc++.h>

using namespace std;

char solve(int B, const vector<int>& xs, const vector<int>& ys)
{
    int i = 0;

    for (auto x : xs)
    {
        if (ys[i] == x)
            ++i;

        if (i == B)
            return 'S';
    }

    return 'N';
}

int main()
{
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;

    vector<int> xs(A), ys(B);

    for (int i = 0; i < A; ++i)
            cin >> xs[i];

    for (int i = 0; i < B; ++i)
            cin >> ys[i];

    cout << solve(B, xs, ys) << '\n';

    return 0;
}
