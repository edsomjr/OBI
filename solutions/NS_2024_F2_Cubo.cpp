#include <bits/stdc++.h>

using namespace std;

auto solve(int N)
{
    int total = N * N * N;
    int _3s = 8;
    int _2s = 12*(N - 2);
    int _1s = 6*(N - 2)*(N - 2);
    int _0s = total - _1s - _2s - _3s;

    return make_tuple(_0s, _1s, _2s, _3s);
}

int main()
{
    int N;
    cin >> N;

    auto [_0s, _1s, _2s, _3s] = solve(N);

    cout << _0s << '\n';
    cout << _1s << '\n';
    cout << _2s << '\n';
    cout << _3s << '\n';

    return 0;
}
