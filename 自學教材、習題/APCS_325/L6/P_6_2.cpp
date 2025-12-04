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
    int n; cin >> n;
    vector<int> v(n), dp(n);
    for (auto &i : v) cin >> i;
    dp[0] = v[0], dp[1] = max(v[0], v[1]);
    for (int i = 2; i < n; i++) dp[i] = max(dp[i-1], dp[i-2] + v[i]);
    cout << dp.back();
}