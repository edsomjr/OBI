#include <bits/stdc++.h>

using namespace std;

auto solve(const string& A, const string& B)
{
    for (auto c : B)
        if (A.find(c) == string::npos)
            return 'N';

    return 'S';
}

int main()
{
    ios::sync_with_stdio(false);

    int K, N;
    cin >> K >> N;

    string A, B;
    cin >> A >> B;

    cout << solve(A, B) << '\n';

    return 0;
}
