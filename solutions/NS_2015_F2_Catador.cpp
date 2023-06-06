// OBI 2015 - Nível Sênior - Fase 2: Catador (https://olimpiada.ic.unicamp.br/pratique/ps/2015/f2/catador/)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class BITree {
public:
    BITree(int n) : ts(n + 2, 0), N(n) {}        

    ll value_at(int i) { return RSQ(i); }

    void range_add(int i, int j, ll x)
    {
        add(i, x);
        add(j + 1, -x);
    }

private:
    vector<ll> ts;
    int N;

    int LSB(int n) { return n & (-n); }

    ll RSQ(int i)
    {
        ll sum = 0;

        while (i >= 1) {
            sum += ts[i];
            i -= LSB(i);
        }

        return sum;
    }

    void add(int i, ll x)
    {
        while (i <= N) {
            ts[i] += x;
            i += LSB(i);
        }
    }
};

ll solve(int N, const vector<int>& xs, const vector<int>& qs)
{
    BITree bt(N);

    for (int i = 1; i <= N; ++i)
        bt.range_add(i, i, xs[i]);

    for (auto q : qs)
    {
        auto C = bt.value_at(q);

        if (C <= 0)
            continue;

        bt.range_add((int) max(1LL, q - C), (int) min((ll) N, q + C), -1);
    }

    ll ans = 0;

    for (int i = 1; i <= N; ++i)
    {
        auto x = bt.value_at(i);

        ans += x > 0 ? x : 0;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> xs(N + 1), qs(M);

    for (int i = 1; i <= N; ++i)
        cin >> xs[i];

    for (int i = 0; i < M; ++i)
        cin >> qs[i];

    cout << solve(N, xs, qs) << '\n';

    return 0;
}
