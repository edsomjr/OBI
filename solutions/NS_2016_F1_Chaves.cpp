// OBI 2016 - Nível Sênior - Fase 1: Chaves (https://olimpiada.ic.unicamp.br/pratique/ps/2016/f1/chaves/)
#include <bits/stdc++.h>

using namespace std;

char solve(const vector<string>& xs)
{
    int open = 0;

    for (auto x : xs)
        for (auto c : x)
        {
            if (c == '{')
                ++open;
            else if (c == '}')
            {
                if (open == 0)
                    return 'N';

                --open;
            }
        }

    return open == 0 ? 'S' : 'N';
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    cin.ignore(1, '\n');

    vector<string> xs(N);

    for (int i = 0; i < N; ++i)
        getline(cin, xs[i]);

    cout << solve(xs) << '\n';

    return 0;
}
