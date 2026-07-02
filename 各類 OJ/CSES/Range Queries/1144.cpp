#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

template<typename T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() { WA();
    int n, q; cin >> n >> q;
    rbtree<PII> t;
    vector<int> v(n);
    for (auto &i : v) cin >> i, t.insert({i, &i-v.data()});

    while (q--) {
        char c; int a, b;
        cin >> c >> a >> b;
        if (c == '!') {
            a--;
            t.erase({v[a], a});
            v[a] = b;
            t.insert({v[a], a});
        }
        else cout << t.order_of_key({b, INF}) - t.order_of_key({a, 0}) << '\n';
    }
}