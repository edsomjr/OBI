// OBI 2017 - Nível Sênior - Fase 2: Dario e Xerxes (https://olimpiada.ic.unicamp.br/pratique/ps/2017/f2/xerxes/)
#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

auto solve(const vector<ii>& rs)
{
    int dario = 0, xerxes = 0;

    for (auto [D, X] : rs)
        X == (D + 1) % 5 or X == (D + 2) % 5 ? ++dario : ++xerxes;

    return dario > xerxes ? "dario" : "xerxes";
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<ii> rs(N);

    for (int i = 0; i < N; ++i)
        cin >> rs[i].first >> rs[i].second;

    cout << solve(rs) << '\n';

    return 0;
}
