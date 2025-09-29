#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n, k, m;
    while (cin >> n >> k >> m) {
        int dp[51][51];
        memset(dp, 0, sizeof(dp)); dp[0][0] = 1;
        
        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
        for (int w = 1; w <= min(i, m); w++) dp[i][j] += dp[i-w][j-1];

        cout << dp[n][k] << '\n';
    }
}