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
    int t; cin >> t;
    for (int T = 1; T <= t; T++) {
        int n, p, q, x; cin >> n >> p >> q;
        vector<int> dp, a(p+1), b(q+1);
        for (auto &i : a) cin >> i;
        for (auto &i : b) {
            cin >> i;
            int idx = find(all(a), i)-a.begin(), k = lower_bound(dp.begin(), dp.end(), idx)-dp.begin();
            if (k == dp.size()) dp.pb(idx);
            else dp[k] = idx;
        }
        cout << "Case " << T << ": " << dp.size() << '\n';
    }
}