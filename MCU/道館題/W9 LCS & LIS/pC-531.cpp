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
    string s;
    while (cin >> s) {
        vector<string> a, b, ans;
        a.pb(s);
        while (cin >> s, s != "#") a.pb(s);
        while (cin >> s, s != "#") b.pb(s);
        int n = sz(a), m = sz(b);
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        while (n && m) {
            if (a[n-1] == b[m-1]) {
                ans.pb(a[n-1]);
                n--; m--;
            }
            else if (dp[n][m] == dp[n][m-1]) m--;
            else n--;
        }
        reverse(all(ans));
        for (auto &i : ans) cout << i << " \n"[&i == &ans.back()];
        a.clear(); b.clear(); ans.clear();
    }
}