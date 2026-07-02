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
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m)), dp = v;
    for (auto &i : v) for (auto &j : i) cin >> j;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!i && !j) dp[i][j] = v[i][j];
            else if (!i) dp[i][j] = dp[i][j-1] + v[i][j];
            else if (!j) dp[i][j] = dp[i-1][j] + v[i][j];
            else dp[i][j] = min({dp[i-1][j], dp[i][j-1]}) + v[i][j];
        }
    }
    cout << dp[n-1][m-1];
}