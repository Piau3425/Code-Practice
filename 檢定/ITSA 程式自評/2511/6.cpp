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
    vector<int> dp(21);
    dp[0] = dp[1] = 1;
    for (int i = 2; i < dp.size(); i++) dp[i] = dp[i-1] + dp[i-2];
    for (int n; cin >> n; cout << dp[n] << '\n');
}