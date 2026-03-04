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
    int t; for (cin >> t; t--;) {
        int n, m; cin >> n >> m;
        vector<int> v(n); for (auto &i : v) cin >> i;
        vector<vector<int>> dp(n, vector<int>(m)); // 
        dp[0][(v[0]%m+m)%m] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i-1][j]) dp[i][((j+v[i])%m+m)%m] = dp[i][((j-v[i])%m+m)%m] = 1;
            }
        }
        if (dp[n-1][0]) cout << "Divisible\n";
        else cout << "Not divisible\n";
    }
}