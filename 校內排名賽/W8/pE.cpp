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
    for (int n, m; cin >> n >> m, n+m;) {
        n++, m++;
        vector<vector<int>> dp(n+1, vector<int>(m+1)), stone = dp;
        int k, a, b;
        for (cin >> k; k--;) {
            cin >> a >> b;
            a++, b++;
            stone[a][b] = 1;
        }
        dp[1][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!stone[i][j]) dp[i][j] += dp[i-1][j] + dp[i][j-1];
            }
        }
        if (dp[n][m] == 1) cout << "There is one path from Little Red Riding Hood's house to her grandmother's house.\n";
        else if (dp[n][m] == 0) cout << "There is no path.\n";
        else  cout << "There are " << dp[n][m] << " paths from Little Red Riding Hood's house to her grandmother's house.\n";
    }
}