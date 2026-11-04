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
    int t; for (cin >> t; t--;) {
        int n; cin >> n;
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        int l = 0, now = 1, ans = 1;
        for (int r = 1; r < n; r++) {
            if (now && v[r-1] > v[r] || !now && v[r-1] < v[r]) {
                now = !now, ans++;
            }
        }
        cout << ans << '\n';
    }
}