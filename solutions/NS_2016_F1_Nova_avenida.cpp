// OBI 2016 - Nível Sênior - Fase 1: Nova avenida (https://olimpiada.ic.unicamp.br/pratique/ps/2016/f1/avenida/)
#include <bits/stdc++.h>

using namespace std;

const int oo { 1'000'000'010 };

int solve(int N, int M, const vector<vector<int>>& A)
{
    int ans = oo;

    for (int col = 0; col < M; ++col)
    {
        int cost = 0;
    
        for (int row = 0; row < N; ++row)
            cost += A[row][col];

        ans = min(ans, cost);
    }

    return ans;    
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(M));

    for (int row = 0; row < N; ++row)
        for (int col = 0; col < M; ++col)
            cin >> A[row][col];

    cout << solve(N, M, A) << '\n';

    return 0;
}
