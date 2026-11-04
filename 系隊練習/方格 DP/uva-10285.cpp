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
        string s; cin >> s;
        int n, m; cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        vector<vector<int>> dp(n, vector<int>(m, -INF));
        vector<TIII> order;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
                order.pb({v[i][j], i, j});
            }
        }
        sort(all(order));
        
        int ans = 0;
        for (auto &[now, i, j] : order) {
            int mx = -INF, x[] = {0, 1, 0, -1}, y[] = {1, 0, -1, 0};
            for (int k = 0; k < 4; k++) {
                int nx = i+x[k], ny = j+y[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[i][j] != v[nx][ny]) mx = max(mx, dp[nx][ny]);
            }
            if (mx == -INF) dp[i][j] = 1;
            else dp[i][j] = mx + 1;
            ans = max(dp[i][j], ans);
        }

        cout << s << ": " << ans << '\n';
    }
}