#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long

signed main() { WA();
    int n, m, t = 0;
    while (cin >> n >> m, n && m) {
        vector<int> a(n), b(m);
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        cout << "Twin Towers #" << ++t << "\nNumber of Tiles : " << dp[n][m] << "\n\n";
    }
}