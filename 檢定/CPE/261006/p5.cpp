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
    for (int n; cin >> n, n;) {
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        unordered_map<int, vector<PII>> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                mp[v[i]+v[j]].pb({i, j});
            }
        }
        int mx = -INF;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (mp.count(v[i]-v[j])) for (auto &k : mp[v[i]-v[j]]) {
                    if (i != k.fi && i != k.se && j != k.fi && j != k.se) mx = max(mx, v[i]);
                }
            }
        }
        if (mx == -INF) cout << "no solution\n";
        else cout << mx << '\n';
    }
}