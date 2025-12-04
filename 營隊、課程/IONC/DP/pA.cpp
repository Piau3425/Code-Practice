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
    int n, k, p = 1e9+7; cin >> n >> k;
    vector<int> v(n), dp(k+1);
    for (auto &i : v) cin >> i;
    sort(all(v));
    dp[0] = 1;
    for (int i = 0; i <= k; i++) for (int j = 0; j < n; j++) if (i >= v[j]) dp[i] = (dp[i]+dp[i-v[j]])%p;
    cout << dp[k];
}