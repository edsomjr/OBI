// NEPS 2715 - Placas de Carro (https://neps.academy/br/exercise/2715)
#include <bits/stdc++.h>

using namespace std;

map<char, function<int(int)>> fs {
    { 'c' , ::isupper }, 
    { 'd' , ::isdigit }, 
    { '-' , [](int c) { return c == '-'; } }
};

auto check(int N, const string& s, const string& spec)
{
    for (int i = 0; i < N; ++i)
        if (not fs[spec[i]](s[i]))
            return false;

    return true;
}

auto solve(const string& s)
{
    if (s.size() == 7ul)
        return check(7, s, "cccdcdd") ? 2 : 0;
    else if (s.size() == 8ul)
        return check(8, s, "ccc-dddd") ? 1 : 0;

    return 0;
}

int main()
{
    string s;
    cin >> s;

    cout << solve(s) << '\n';

    return 0;
}
