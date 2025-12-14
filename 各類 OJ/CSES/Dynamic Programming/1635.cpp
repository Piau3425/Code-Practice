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
    int n, x, p = 1e9+7; cin >> n >> x;
    vector<int> v(n), dp(x+1); dp[0] = 1;
    for (auto &i : v) cin >> i; sort(all(v));
    for (int i = 1; i <= x; i++) {
        for (auto &j : v) {
            if (i-j >= 0) {
                dp[i] += dp[i-j];
                if (dp[i] >= p) dp[i] -= p;
            }
            else break;
        }
    }
    cout << dp[x] << '\n';
}