// NEPS 2714 - Jogo da Vida (https://neps.academy/br/exercise/2714)
#include <bits/stdc++.h>

using namespace std;

auto solve(int N, int Q, vector<string>& A)
{
    auto B = A;

    while (Q--)
    {
        for (int x = 0; x < N; ++x)
            for (int y = 0; y < N; ++y)
            {
                int n = 0;

                for (int dx = -1; dx <= 1; ++dx)
                    for (int dy = -1; dy <= 1; ++dy)
                    {
                        if (dx == 0 and dy == 0)
                            continue;

                        int u = x + dx, v = y + dy;

                        if (0 <= u and u < N and 0 <= v and v < N and A[u][v] == '1')
                            ++n;
                    }

                B[x][y] = (A[x][y] == '0' and n == 3) or (A[x][y] == '1' and 2 <= n and n <= 3) ? '1' : '0';
            }

        A.swap(B);
    }

    return A;
}

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<string> A(N);

    for (auto& line : A)
        cin >> line;

    auto ans = solve(N, Q, A);

    for (auto x : ans)
        cout << x << '\n';

    return 0;
}
