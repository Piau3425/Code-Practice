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
    for (int n, T = 0; cin >> n, ~n;) {
        vector<int> dp, a, b; a.pb(n);
        for (; cin >> n, ~n;) a.pb(n);
        b = a; sort(all(b), greater<int>());
        for (auto &i : b) {
            int idx = find(all(a), i)-a.begin(), k = lower_bound(dp.begin(), dp.end(), idx)-dp.begin();
            if (k == dp.size()) dp.pb(idx);
            else dp[k] = idx;
        }
        if (T) cout << '\n';
        cout << "Test #" << ++T << ":\n  maximum possible interceptions: " << dp.size() << '\n';
    }
}