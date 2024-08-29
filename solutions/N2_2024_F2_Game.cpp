#include <bits/stdc++.h>

using namespace std;

auto solve(const string& s)
{
    auto ans = 1;

    for (auto c : s)
        ans = c == 'E' ? 2*ans : 2*ans + 1;

    return ans;
}

int main()
{
    int N;
    string s;
    cin >> N >> s;

    cout << solve(s) << '\n';

    return 0;
}
