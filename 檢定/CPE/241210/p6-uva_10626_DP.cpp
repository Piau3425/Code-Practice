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

int k, dp[800][300][100];

int dfs(int a, int b, int c) {
    if (k == a + b*5 + c*10) return 0;
    if (dp[a][b][c]) return dp[a][b][c];
    dp[a][b][c] = INF;
    if (c > 0) dp[a][b][c] = min(dp[a][b][c], dfs(a+2, b, c-1) + 1);
    if (c > 0 && a >= 3) dp[a][b][c] = min(dp[a][b][c], dfs(a-3, b+1, c-1) + 4);
    if (b >= 2) dp[a][b][c] = min(dp[a][b][c], dfs(a+2, b-2, c) + 2);
    if (b > 0 && a >= 3) dp[a][b][c] = min(dp[a][b][c], dfs(a-3, b-1, c) + 4);
    if (a >= 8) dp[a][b][c] = min(dp[a][b][c], dfs(a-8, b, c) + 8);
    return dp[a][b][c];
}

signed main() { WA();
    int t, n, a, b, c;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b >> c;
        k = a + b*5 + c*10 - n*8;
        memset(dp, 0, sizeof(dp));
        cout << dfs(a, b, c) << '\n';
    }
}