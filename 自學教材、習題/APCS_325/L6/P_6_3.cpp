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
    int n; cin >> n;
    vector<int> v(n), dp(n);
    for (auto &i : v) cin >> i;
    dp[0] = v[0], dp[1] = v[1], dp[2] = v[2] + min(v[0], v[1]);
    for (int i = 3; i < n; i++) dp[i] = v[i] + min({dp[i-1], dp[i-2], dp[i-3]});
    cout << min(dp[n-1], dp[n-2]);
}