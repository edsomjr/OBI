// OBI 2015 - Nível Sênior - Fase 2: Número Napolitano (https://olimpiada.ic.unicamp.br/pratique/ps/2015/f2/napolitano/)
#include <bits/stdc++.h>

using namespace std;

map<char, int> value_of { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };

auto solve(const string& s)
{
    auto N = (int) s.size();
    vector<int> xs(N), vs(N), next(N, -1);

    for (int i = 0; i < N; ++i)
        xs[i] = vs[i] = value_of[s[i]];

    for (int i = N - 2; i >= 0; --i)
    {
        auto p = i + 1;

        while (p != -1 and xs[i] >= xs[p])
            p = next[p];

        next[i] = p;
    }

    int ans = 0;

    for (int i = 0; i < N; ++i)
    {
        if (next[i] == -1)
            ans += xs[i];
        else
            xs[next[i]] -= xs[i];
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    cout << solve(s) << '\n';

    return 0;
}
