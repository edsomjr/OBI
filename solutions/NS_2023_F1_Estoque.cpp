// NEPS 2319: Estoque (https://neps.academy/br/exercise/2319)
#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int solve(vector<vector<int>>& A, const vector<ii>& xs)
{
    int ans = 0;

    for (auto [x, y] : xs)
        if (A[x][y] > 0)
        {
            ++ans;
            --A[x][y];
        }

    return ans;
}

int main()
{
    int M, N;
    cin >> M >> N;

    vector<vector<int>> A(M + 1, vector<int>(N + 1));

    for (int i = 1; i <= M; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> A[i][j];

    int P;
    cin >> P;

    vector<ii> xs(P);

    for (int i = 0; i < P; ++i)
        cin >> xs[i].first >> xs[i].second;
 
    cout << solve(A, xs) << '\n';

    return 0;
}
