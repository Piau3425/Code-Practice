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
    int n, m, tv = 0;
    cin >> n >> m;
    vector<PII> v(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i].fi >> v[i].se, tv += v[i].se;
    vector<int> dp(tv+1, INF); dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = tv; j >= v[i].se; j--) dp[j] = min(dp[j], dp[j-v[i].se]+v[i].fi);
    }
    int ans = 0;
    for (int i = 1; i <= tv; i++) {
        if (dp[i] <= m) ans = i;
    }
    cout << ans;
}
