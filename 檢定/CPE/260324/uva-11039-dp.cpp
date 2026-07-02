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
    int t; for (cin >> t; t--;) {
        vector<PII> v;
        int n; for (cin >> n; n--;) {
            int x; cin >> x;
            v.pb({abs(x), x < 0});
        }
        sort(all(v), greater<PII>());
        int dp[2] = {0, 0};
        for (auto [val, neg] : v) dp[neg] = max(dp[neg], dp[1-neg]+1);
        cout << max(dp[0], dp[1]) << '\n';
    }
}