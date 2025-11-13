#include <bits/stdc++.h>
using namespace std;

#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long

signed main() { WA();
    int t; for (cin >> t; t--;) {
        int n, m; cin >> n;
        vector<int> p(n), w(n);
        for (int i = 0; i < n; i++) cin >> p[i] >> w[i];
        int ans = 0;
        for (cin >> m; m--;) {
            int k; cin >> k;
            vector<int> dp(k+1);
            for (int i = 0; i < n; i++) {
                for (int j = k; j >= w[i]; j--) {
                    dp[j] = max(dp[j], dp[j-w[i]] + p[i]);
                }
            }
            ans += dp[k];
        }
        cout << ans << '\n';
    }
}