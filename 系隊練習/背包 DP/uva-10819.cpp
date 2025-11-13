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
    int m, n; while (cin >> m >> n) {
        vector<PII> v(n);
        for (auto &i : v) cin >> i.fi >> i.se;
        vector<int> dp(m+1+200);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = m+200; j >= v[i].fi; j--) if (dp[j-v[i].fi] || j == v[i].fi) {
                dp[j] = max(dp[j], dp[j-v[i].fi]+v[i].se);
                // if (j <= m || (j > m && j > 2000))
                if (j <= m || j > 2000) ans = max(ans, dp[j]);
            }
        }
        cout << ans << '\n';
    }
}