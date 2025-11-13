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
    vector<int> v(n), w(n), dp(x+1);
    for (auto &i : w) cin >> i;
    for (auto &i : v) cin >> i;
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        }
    }
    cout << dp[x] << '\n';
}