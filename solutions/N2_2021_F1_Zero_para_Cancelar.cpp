// OBI 2021 - Fase 1 - Zero para cancelar (https://olimpiada.ic.unicamp.br/pratique/p2/2021/f1/zero/)
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> xs;

    while (N--)
    {
        int x;
        cin >> x;

        x ? xs.push_back(x) : xs.pop_back();
    }

    cout << accumulate(xs.begin(), xs.end(), 0) << '\n';

    return 0;
} 
