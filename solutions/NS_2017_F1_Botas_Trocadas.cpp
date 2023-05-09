// OBI 2017 - Nível Sênior - Fase 1: Botas Trocadas (https://olimpiada.ic.unicamp.br/pratique/ps/2017/f1/botas/)
#include <bits/stdc++.h>

using namespace std;
using ic = pair<int, char>;

auto solve(int N, vector<ic>& shoes)
{
    sort(shoes.begin(), shoes.end());

    ic last { 0, ' ' };
    int count = 0, ans = 0;

    for (int L = 0, R = 1; L < N; L = R, R = L + 1)
    {
        while (R < N and shoes[R] == shoes[L])        
            ++R;

        if (shoes[L].first == last.first)
            ans += min(R - L, count);

        last = shoes[L];
        count = R - L;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<ic> shoes(N);

    for (int i = 0; i < N; ++i)
        cin >> shoes[i].first >> shoes[i].second;

    cout << solve(N, shoes) << '\n';

    return 0;
}
