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
    int t; for (cin >> t; t--;) {
        int n; cin >> n;
        vector<int> w(n), v(n);
        for (auto &i : v) cin >> i >> w[&i-v.data()];
        vector<int> dp(30+1);
        for (int i = 0; i < n; i++) {
            for (int j = 30; j >= w[i]; j--) dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
        int k, sum = 0; for (cin >> k; k--;) {
            int W; cin >> W;
            sum += dp[W];
        }
        cout << sum << '\n';
    }
}