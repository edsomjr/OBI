// NEPS 2713 - Relógio (https://neps.academy/br/exercise/2713)
#include <bits/stdc++.h>

using namespace std;

auto solve(int H, int M, int S, int T) -> tuple<int, int, int>
{
    int start = (3600*H + 60*M + S) + T;

    int s = start % 60;
    start /= 60;

    int m = start % 60;
    start /= 60;

    int h = start % 24;

    return { h, m, s };
}

int main()
{
    int H, M, S, T;
    cin >> H >> M >> S >> T;

    auto [h, m, s] = solve(H, M, S, T);

    cout << h << '\n';
    cout << m << '\n';
    cout << s << '\n';

    return 0;
}
