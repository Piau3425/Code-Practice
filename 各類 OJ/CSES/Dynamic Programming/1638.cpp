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
    int n, p = 1e9+7; cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    for (auto &i : v) for (auto &j : i) cin >> j; dp[1][1] = v[0][0] == '.';
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        if (v[i-1][j-1] != '*') dp[i][j] += (dp[i-1][j] + dp[i][j-1])%p;
    }
    cout << dp[n][n] << '\n';
}