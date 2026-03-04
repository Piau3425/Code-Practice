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
    int t; for (cin >> t; t--;) {
        int n; string s; cin >> n >> s;
        int dp1 = 0, dp2 = 0, b = 0, ans1 = 0, p2 = 1;
        for (auto &c : s) {
            int sum = (1 + dp1 + dp2) % MOD;

            if (c == '(') (ans1 += p2) %= MOD, b++, dp1 = (dp1 + sum) % MOD;
            else b--, dp2 = (dp2 + sum) % MOD;

            if (b <= 1) dp1 = 0;

            p2 = p2 * 2 % MOD;
        }
        cout << (ans1 + dp2) % MOD << '\n';
    }
}