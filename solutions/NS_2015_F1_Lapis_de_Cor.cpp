// OBI 2015 - Nível Sênior - Fase 1: Lápis de Cor (https://olimpiada.ic.unicamp.br/pratique/ps/2015/f1/cor/)
#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const vector<ii> dirs { ii(-1, 0), ii(1, 0), ii(0, -1), ii(0, 1) };

auto solve(int N, const vector<string>& A)
{
    vector<string> B(N, string(N, '9'));

    queue<ii> q;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            if (A[i][j] == '0')
            {
                B[i][j] = '0';
                q.push(ii(i, j));
            }
        }

    while (not q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (B[x][y] == '9')
            continue;

        for (auto [dx, dy] : dirs)
        {
            auto u = x + dx, v = y + dy;

            if (0 <= u and u < N and 0 <= v and v < N and B[u][v] > B[x][y] + 1)
            {
                B[u][v] = B[x][y] + 1;
                q.push(ii(u, v));
            }
        }
    }

    return B;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<string> A(N);

    for (int i = 0; i < N; ++i)
        cin >> A[i];

    auto ans = solve(N, A);

    for (auto row : ans)
        cout << row << '\n';

    return 0;
}
