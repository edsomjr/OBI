// OBI 2014 - Nível Sênior - Fase 1: Carteiro (https://olimpiada.ic.unicamp.br/pratique/ps/2014/f1/carteiro/)
#include <bits/stdc++.h>

using namespace std;

long long solve(const vector<int>& xs, const vector<int>& ys)
{
    long long ans = 0;
    long pos = 0;

    for (auto y : ys)
    {
        auto next = lower_bound(xs.begin(), xs.end(), y) - xs.begin();
        ans += abs(next - pos);
        pos = next;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<int> xs(N), ys(M);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    for (int i = 0; i < M; ++i)
        cin >> ys[i];

    cout << solve(xs, ys) << '\n';

    return 0;
}
