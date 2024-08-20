#include <bits/stdc++.h>

using namespace std;
using sii = tuple<string, int, int>;

auto solve(int N, int M, const vector<sii>& qs)
{
    vector<int> rows(N), cols(M);
    iota(rows.begin(), rows.end(), 0);
    iota(cols.begin(), cols.end(), 0);

    for (auto [cmd, A, B] : qs)
    {
        --A; --B;
        cmd == "L" ? swap(rows[A], rows[B]) : swap(cols[A], cols[B]);
    }

    vector<vector<int>> ans(N, vector<int>(M));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            ans[i][j] = cols[j] + M*rows[i] + 1;

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M, P;
    cin >> N >> M >> P;

    vector<sii> qs(P);

    for (auto& [s, A, B] : qs)
        cin >> s >> A >> B;

    auto ans = solve(N, M, qs);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cout << ans[i][j] << (j + 1 == M ? '\n' : ' ');

    return 0;
}
