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
    int n;
    for (cin >> n, cin.ignore(); n; n--) {
        string a, b;
        getline(cin, a); b = string(a.rbegin(), a.rend());
        int n = sz(a);
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        cout << dp[n][n] << '\n';
    }
}