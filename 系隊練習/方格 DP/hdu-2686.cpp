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

int dp[75][35][35];

signed main() { WA();
    for (int n; cin >> n;) {
        vector<vector<int>> v(n, vector<int>(n));
        for (auto &i : v) for (auto &j : i) cin >> j;
        memset(dp, -1, sizeof(dp)); dp[0][0][0] = v[0][0];
        for (int k = 1; k <= n+n-2; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int ii = k-i, jj = k-j;
                    if (ii < 0 || jj < 0 || ii >= n || jj >= n) continue;
                    dp[k][i][j] = max({dp[k-1][i][j], dp[k-1][i-1][j], dp[k-1][i][j-1], dp[k-1][i-1][j-1]});
                    if (i == j) dp[k][i][j] += v[i][ii];
                    else dp[k][i][j] += v[i][ii] + v[j][jj];
                }
            }
        }

        cout << dp[n+n-2][n-1][n-1] << '\n';
    }
}