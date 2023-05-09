// OBI 2017 - Nível Sênior - Fase 1: Palíndromo (https://olimpiada.ic.unicamp.br/pratique/ps/2017/f1/palindromo/)
#include <bits/stdc++.h>

using namespace std;

const int MAX { 2'010 };

int state[MAX], is_p[MAX][MAX];


int is_palindrome(int i, int j, const string& s)
{
    if (i > j)
        return 1;

    if (s[i] != s[j])
        return 0;

    if (is_p[i][j] != -1)
        return is_p[i][j];

    auto res = is_palindrome(i + 1, j - 1, s);

    is_p[i][j] = res;

    return res;
}

int min_cuts(int i, int N, const string& s)
{
    if (i == N)
        return 0;

    if (state[i] != -1)
        return state[i];

    int res = 1 + min_cuts(i + 1, N, s);

    for (int j = i + 1; j < N; ++j)
        if (is_palindrome(i, j, s))
            res = min(res, 1 + min_cuts(j + 1, N, s));

    state[i] = res;

    return res;
}

auto solve(int N, const string& s)
{
    memset(state, -1, sizeof state);
    memset(is_p, -1, sizeof is_p);

    return min_cuts(0, N, s);
}

int main()
{
    int N;
    string s;

    cin >> N >> s;

    cout << solve(N, s) << '\n';

    return 0;
}
