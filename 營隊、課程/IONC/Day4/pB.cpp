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
    int n, mx = -1e9; cin >> n;
    vector<int> v(n+1), dp(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i], dp[i] = v[i];
    for (int i = 1; i <= n; i++) for (int j = 1; j < i; j++) {
        if (v[i] >= v[j]) dp[i] = max(dp[i], dp[j]+v[i]);
    }
    for (auto &i : dp) mx = max(mx, i);
    cout << mx;
}