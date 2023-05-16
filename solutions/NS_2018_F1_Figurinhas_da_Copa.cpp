// OBI 2018 - Nível Sênior - Fase 1: Figurinhas da Copa (https://olimpiada.ic.unicamp.br/pratique/ps/2018/f1/figurinhas/)
#include <bits/stdc++.h>

using namespace std;

auto solve(set<int>& xs, vector<int>& ys)
{
    for (auto y : ys)
        xs.erase(y);

    return xs.size();
}

int main()
{
    ios::sync_with_stdio(false);

    int N, C, M;
    cin >> N >> C >> M;

    set<int> xs;

    while (C--)
    {
        int x;
        cin >> x;

        xs.insert(x);
    }

    vector<int> ys(M);

    for (int i = 0; i < M; ++i)
        cin >> ys[i];

    cout << solve(xs, ys) << '\n';

    return 0;
}
