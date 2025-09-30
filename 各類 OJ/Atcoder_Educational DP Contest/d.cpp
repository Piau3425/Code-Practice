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
    int n, m;
    cin >> n >> m;
    vector<PII> v(n+1);
    vector<int> dp(m+1);
    for (int i = 1; i <= n; i++) cin >> v[i].fi >> v[i].se;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i].fi; j--) dp[j] = max(dp[j], dp[j-v[i].fi]+v[i].se);
    }
    cout << dp[m];
}
