#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n, k, mx = -1e9; cin >> n >> k;
    vector<int> p(n+1), dp(n+1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= k+1; i++) dp[i] = max(dp[i-1], p[i]);
    for (int i = k+2; i <= n; i++) dp[i] = max(dp[i-1], dp[i-k-1]+p[i]);
    cout << dp[n];
}