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
    int n, l; cin >> n >> l;
    vector<int> v(n+1), dp(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (v[j] < v[i] && abs(i-j) <= l) dp[i] = max(dp[i], dp[j]+1);
        }
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) mx = max(mx, dp[i]);
    int idx;
    vector<int> ans;
    for (int i = 1; i <= n; i++) if (dp[i] == mx) idx = i;
    while (dp[idx] > 1) {
        ans.pb(v[idx]);
        for (int i = idx-1; i > 0; i--) {
            if (dp[i] == dp[idx]-1) {
                idx = i;
                break;
            }
        }
    }
    ans.pb(v[idx]);
    cout << mx << '\n';
    for (auto &i : vector<int>(ans.rbegin(), ans.rend())) cout << i << ' ';
}