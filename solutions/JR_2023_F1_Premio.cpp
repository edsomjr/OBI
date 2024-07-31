// NEPS 2313: Prêmio (https://neps.academy/br/exercise/2313)
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int P, D, B;
    cin >> P >> D >> B;

    auto score = P + 2*D + 3*B;

    vector<int> xs { 99, 119, 149, 1'000'000'000 };
    string ans { "NPDB" };
    
    cout << ans[lower_bound(xs.begin(), xs.end(), score) - xs.begin()] << '\n';

    return 0;
}

