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
    int n, x; cin >> n >> x;
    vector<int> v(n), dp(x+1, INF); dp[0] = 0;
    for (auto &i : v) cin >> i;
    for (int i = 0; i < n; i++) {
        for (int j = v[i]; j <= x; j++) {
            dp[j] = min(dp[j], dp[j-v[i]]+1);
        }
    }
    if (dp[x] == INF) cout << "-1\n";
    else cout << dp[x] << '\n';
}