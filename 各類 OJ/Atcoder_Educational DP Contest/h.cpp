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
    int n, m, p = 1e9+7; cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<int>> dp(n+1, vector<int>(m+1)); dp[0][0] = 1;
    for (auto &i : v) for (auto &j : i) cin >> j;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int &now = dp[i][j];
            if (i-1 >= 0 && v[i-1][j] == '.') now = (now + dp[i-1][j])%p;
            if (j-1 >= 0 && v[i][j-1] == '.') now = (now + dp[i][j-1])%p;
        }
    }
    cout << dp[n-1][m-1]%p;
}