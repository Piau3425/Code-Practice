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
    int n, m; cin >> n >> m;
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; i++) dp[i][0] = i;
    for (int i = 1; i <= m; i++) dp[0][i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == j) continue;
            int mn = INF;
            for (int k = 1; k < i; k++) mn = min(mn, dp[i-k][j]+dp[k][j]+1);
            for (int k = 1; k < j; k++) mn = min(mn, dp[i][j-k]+dp[i][k]+1);
            dp[i][j] = mn;
        }
    }
    cout << dp[n][m];
}