#include <bits/stdc++.h>

using namespace std;

auto solve(const string& A, const string& B, int TA, int TB)
{
    TA = A == "C" ? 9*TA : (TA - 32)*5;
    TB = B == "C" ? 9*TB : (TB - 32)*5;

    return TA < TB ? "A" : "B";
}

int main()
{
    string A, B;
    cin >> A >> B;

    int TA, TB;
    cin >> TA >> TB;

    cout << solve(A, B, TA, TB) << '\n';

    return 0;
}
