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
#define TIII tuple<int, int, int>

template<typename T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() { WA();
    int cas = 0;
    for (int n, q; cin >> n >> q, n+q;) { cout << "CASE# " << ++cas << ":\n";
        vector<int> v(n); for (auto &i : v) cin >> i;
        sort(all(v));
        while (q--) {
            int x; cin >> x;
            auto it = lower_bound(all(v), x);
            if (*it != x) cout << x << " not found\n";
            else cout << x << " found at " << it - v.begin() +1 << '\n';
        }
    }
}