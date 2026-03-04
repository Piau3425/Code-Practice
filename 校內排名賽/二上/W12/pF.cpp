#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    for (int n, k, m; cin >> n >> k >> m;) { // 幾條，幾塊，一塊最多幾條
        vector<vector<int>> dp(n+1, vector<int>(k+1)); // 幾條，幾塊
        dp[0][0] = 1;
        for (int i = 1; i <= k; i++)
        for (int j = 0; j <= n; j++)
        for (int len = 1; len <= m; len++)
        if (j >= len) dp[j][i] += dp[j-len][i-1];
        cout << dp[n][k] << '\n';
    }
}