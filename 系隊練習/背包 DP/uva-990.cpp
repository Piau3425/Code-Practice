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
    int T = 0;
    for (int t, h; cin >> t >> h;) {
        if (T++) cout << '\n';
        int n; cin >> n;
        vector<int> p(n+1), w(n+1);
        for (int i = 1; i <= n; i++) cin >> w[i] >> p[i];
        vector<vector<int>> dp(n+1, vector<int>(t+1));
        map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= t; j++) {
                if (j-3*w[i]*h < 0) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j], dp[i-1][j-3*w[i]*h]+p[i]);
            }
        }
        stack<int> sk;
        for (int i = n, j = t; i > 0; i--) {
            if (j >= 0 && dp[i][j] != dp[i-1][j]) j -= 3*w[i]*h, sk.push(i);
        }
        cout << dp[n][t] << '\n' << sk.size() << '\n';
        while (sk.size()) cout << w[sk.top()] << ' ' << p[sk.top()] << '\n', sk.pop();
    }
}