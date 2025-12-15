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
    int p = 1e9+7;
    vector<vector<int>> dp(2, vector<int>(1000000+1)); // 0 沒切 1 切一半
    dp[0][1] = 1; dp[1][1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        dp[0][i] = (2*dp[0][i-1]%p + dp[1][i-1])%p;
        dp[1][i] = (dp[0][i-1] + 4*dp[1][i-1]%p)%p;
    }
    int t; for (cin >> t; t--;) {
        int n; cin >> n;
        cout << (dp[0][n] + dp[1][n])%p << '\n';
    }
}