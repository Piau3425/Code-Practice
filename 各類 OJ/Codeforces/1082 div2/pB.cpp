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
    int t;
    for (cin >> t; t--;) {
        int n; string s; cin >> n >> s;

        vector<int> dp = {1, 0}, ndp(2);

        for (int k = 0; k < n; k++) {
            ndp[0] = ndp[1] = 0;
            for (int p = 0; p < 2; p++) if (dp[p]) {
                if (s[k] == '?' || s[k] == (p ? 'b' : 'a')) ndp[p^1] = 1;
                if (s[k] == '?' || s[k] == (((n-k+p)&1) ? 'a' : 'b')) ndp[p] = 1;
            }
            dp[0] = ndp[0], dp[1] = ndp[1];
        }

        if (dp[0] | dp[1]) cout << "YES\n"; else cout << "NO\n";
    }
}