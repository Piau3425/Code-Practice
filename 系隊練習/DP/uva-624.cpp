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
    int n, m;
    while (cin >> n >> m) {
        vector<int> v(m+1), dp(n+1);
        map<int, int> mp;
        for (int i = 1; i <= m; i++) cin >> v[i];
        for (int i = 1; i <= m; i++) {
            for (int j = n; j >= v[i]; j--) {
                if (dp[j-v[i]] + v[i] > dp[j]) {
                    dp[j] = dp[j-v[i]] + v[i];
                    mp[j] = i;
                }
            }
        }

        int k = 0;
        for (int i = 0; i <= n; i++) if (dp[i] > dp[k]) k = i;
        while (k > 0) {
            cout << v[mp[k]] << ' ';
            k -= v[mp[k]];
        }
        cout << "sum:" << dp[n] << '\n';
    }
}