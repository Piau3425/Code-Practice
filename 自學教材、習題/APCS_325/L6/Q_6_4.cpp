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
    int n, t; cin >> n >> t;
    vector<PII> v(n), dp(n);
    for (auto &i : v) cin >> i.fi >> i.se;
    dp[0].fi = abs(t-v[0].fi), dp[0].se = abs(t-v[0].se);
    for (int i = 1; i < n; i++) {
        auto &now = v[i], pCost = dp[i-1], t = v[i-1];
        dp[i].fi = min(pCost.fi+abs(t.fi-now.fi), pCost.se+abs(t.se-now.fi));
        dp[i].se = min(pCost.fi+abs(t.fi-now.se), pCost.se+abs(t.se-now.se));
    }
    cout << min(dp.back().fi, dp.back().se);
}