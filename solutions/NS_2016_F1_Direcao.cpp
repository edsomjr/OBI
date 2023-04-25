// OBI 2016 - Nível Sênior - Fase 1: Direção (https://olimpiada.ic.unicamp.br/pratique/ps/2016/f1/direcao/)
#include <bits/stdc++.h>

using namespace std;

const vector<string> dirs { "norte", "leste", "sul", "oeste", "norte", "leste", "sul" };

auto solve(const string& from, const string& to)
{
    auto it = find(dirs.begin(), dirs.end(), from);
    auto jt = find(it, dirs.end(), to);

    auto xt = find(dirs.rbegin(), dirs.rend(), from);
    auto yt = find(xt, dirs.rend(), to);

    return 90 * min(jt - it, yt - xt);
}

int main()
{
    string from, to;
    cin >> from >> to;

    cout << solve(from, to) << '\n';

    return 0;
}
