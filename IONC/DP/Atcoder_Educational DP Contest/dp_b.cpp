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
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    vector<int> dp(n, INF); dp[0] = 0;
    for (int i = 1; i <= min(n-1, k); i++) {
        dp[i] = abs(v[i]-v[0]);
    }
    for (int i = k+1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i] = min(dp[i], dp[i-j] + abs(v[i]-v[i-j]));
        }
    }
    cout << dp[n-1];
}