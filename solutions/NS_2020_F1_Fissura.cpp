// NEPS 825 - Fissura Perigora (https://neps.academy/br/exercise/825)
#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

vector<ii> dirs { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

auto solve(int N, int F, vector<string>& A)
{
    F += '0';

    if (A[0][0] > F)
        return A;

    queue<ii> q;
    q.emplace(0, 0);
    A[0][0] = '*';

    while (not q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : dirs)
        {
            auto u = x + dx, v = y + dy;

            if (0 <= u and u < N and 0 <= v and v < N and A[u][v] != '*' and A[u][v] <= F)
            {
                A[u][v] = '*';
                q.emplace(u, v);
            }
        }
    }

    return A; 
}

int main()
{
    int N, F;
    cin >> N >> F;

    vector<string> A(N);

    for (auto& line : A)
        cin >> line;

    auto ans = solve(N, F, A);

    for (auto x : A)
        cout << x << '\n';

    return 0;
}

