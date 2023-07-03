// OBI 2016 - Nível Sênior - Fase 2: Arco e flecha (https://olimpiada.ic.unicamp.br/pratique/ps/2016/f2/arco-online/)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ii = pair<ll, ll>;

// Ref: https://opensource.apple.com/source/llvmgcc42/llvmgcc42-2336.9/libstdc++-v3/testsuite/ext/pb_ds/example/tree_order_statistics.cc
// Ref: https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/testsuite/ext/pb_ds/example/tree_order_statistics.cc
// Ref: https://codeforces.com/blog/entry/11080

// A red-black tree table storing ints and their order
// statistics. Note that since the tree uses
// tree_order_statistics_node_update as its update policy, then it
// includes its methods by_order and order_of_key.
typedef
tree<
  ll,
  null_type,
  less_equal<ll>,
  rb_tree_tag,
  // This policy updates nodes' metadata for order statistics.
  tree_order_statistics_node_update>
set_t;


auto solve(int, const vector<ii>& ps)
{
    vector<int> ans;
    auto prev = 0;

    set_t dist;

    for (auto [x, y] : ps)
    {
        x += prev;
        y += prev;

        auto d = x * x + y*y;
        ans.emplace_back(dist.order_of_key(d + 1));
        
        dist.insert(d);
        prev = ans.back();
    }
 
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<ii> ps(N);

    for (int i = 0; i < N; ++i)
        cin >> ps[i].first >> ps[i].second;

    auto ans = solve(N, ps);

    for (auto x : ans)
        cout << x << '\n';

    return 0;
}
