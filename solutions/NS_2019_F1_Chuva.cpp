// OBI 2019 - Nível Sênior - Fase 1: Chuva (https://olimpiada.ic.unicamp.br/pratique/pu/2019/f1/chuva/)
#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

auto solve(int N, int M, vector<string>& A)
{
    queue<ii> q;

    for (int col = 0; col < M; ++col)
        if (A[0][col] == 'o')
        {
            q.emplace(0, col);
            break;
        }

    while (not q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (x == N - 1)
            continue;

        if (A[x + 1][y] == '.')
        {
            A[x + 1][y] = 'o';
            q.emplace(x + 1, y);
        } else if (A[x + 1][y] == '#')
        {
            if (A[x][y - 1] == '.')
            { 
                A[x][y - 1] = 'o';
                q.emplace(x, y - 1);
            }
            
            if (A[x][y + 1] == '.')
            { 
                A[x][y + 1] = 'o';
                q.emplace(x, y + 1);
            }
        }
    }

    return A;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<string> A(N);

    for (int i = 0; i < N; ++i)
        cin >> A[i];

    auto ans = solve(N, M, A);

    for (auto line : ans)
        cout << line << '\n';

    return 0;
} 
