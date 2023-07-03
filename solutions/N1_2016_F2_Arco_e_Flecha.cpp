// OBI 2016 - Nível Sênior - Fase 2: Arco e flecha (https://olimpiada.ic.unicamp.br/pratique/ps/2016/f2/arco-online/)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point { ll x, y; };

class BITree {
private:
    vector<ll> ts;
    int N;

public:
    BITree(int n) : ts(n + 1, 0), N(n) {}

    ll RSQ(int i, int j)
    {
        return RSQ(j) - RSQ(i - 1);
    }

private:
    int LSB(int n) { return n & (-n); }

    ll RSQ(int i)
    {
        ll sum = 0;

        while (i >= 1)
        {
            sum += ts[i];
            i -= LSB(i);
        }

        return sum;
    }

public:
    void add(int i, ll x)
    {
        if (i == 0)
            return;

        while (i <= N)
        {
            ts[i] += x;
            i += LSB(i);
        }
    }
};

ll solve(int N, const vector<Point>& ps)
{
    vector<ll> dist(N);
    set<ll> ds;

    for (int i = 0; i < N; ++i)
    {
        dist[i] = ps[i].x * ps[i].x + ps[i].y * ps[i].y;
        ds.insert(dist[i]);
    }
 
    map<ll, int> idx;
    int j = 0;

    for (auto d : ds)
        idx[d] = ++j;
 
    BITree tree(N);
    ll ans = 0;

    for (int i = 0; i < N; ++i)
    {
        ans += tree.RSQ(0, idx[dist[i]]);

        tree.add(idx[dist[i]], 1);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<Point> ps(N);

    for (int i = 0; i < N; ++i)
        cin >> ps[i].x >> ps[i].y;

    auto ans = solve(N, ps);

    cout << ans << '\n';

    return 0;
}
