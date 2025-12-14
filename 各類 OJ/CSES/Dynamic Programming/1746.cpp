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

int p = 1e9+7;

/*
dp[i][j] = 第 i 格湊成 j 的可能數
dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]
*/

signed main() { WA();
    int n, m; cin >> n >> m;
    vector<int> v(n);
    vector<vector<int>> dp(2, vector<int>(m+2));
    for (auto &i : v) cin >> i;

    if (v[0]) dp[1][v[0]] = 1;
    else for (int i = 1; i <= m; i++) dp[1][i] = 1;

    for (int i = 1; i < n; i++) {
        dp[0] = dp[1];
        fill(all(dp[1]), 0);
        for (int j = 1; j <= m; j++) {
            if (v[i] && v[i] != j) continue;
            dp[1][j] = (dp[0][j-1] + dp[0][j] + dp[0][j+1])%p;
        }
    }

    int sum = 0;
    for (int i = 1; i <= m; i++) sum = (sum + dp[1][i])%p;
    cout << sum << '\n';
}