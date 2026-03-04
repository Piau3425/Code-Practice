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
#define MOD 998244353

signed main() { WA();
    int t;
    for (cin >> t; t--;) {
        int n; cin >> n;
        vector<int> a(n); for (auto &i : a) cin >> i;
        vector<int> dp(n+1, 0), pi(n, 0);
        dp[0] = 1;
        
        for (int L = 1; L <= n; L++) {
            dp[L] = (dp[L] + dp[L-1]) % MOD;
            for (int i = 1, j = 0; i < n-L+1; i++) {
                while (j > 0 && a[L-1+i] != a[L-1+j]) j = pi[j-1];
                if (a[L-1+i] == a[L-1+j]) j++;

                pi[i] = j; if (!j) dp[L+i] = (dp[L+i] + dp[L-1]) % MOD;
            }
        }
        cout << dp[n] << "\n";
    }
}