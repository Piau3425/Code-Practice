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

int p = (1e9+7);

signed main() { WA();
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n+1, vector<char>(m+1, '.'));
    vector<vector<int>> dp(n+1, vector<int>(m+1)), r = dp, c = dp, d = dp; d[0][0] = 1;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> v[i][j];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (v[i][j] != '#') {
        dp[i][j] = ((r[i][j-1] + c[i-1][j])%p + d[i-1][j-1])%p;
        if (i == 1 && j == 1) d[0][0] = 0;
        r[i][j] = (r[i][j-1] + dp[i][j])%p;
        c[i][j] = (c[i-1][j] + dp[i][j])%p;
        d[i][j] = (d[i-1][j-1] + dp[i][j])%p;
    }

    cout << dp[n][m] << '\n';
}