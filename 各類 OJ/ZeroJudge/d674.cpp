 /*
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
#include <bits/stdc++.h>
using namespace std;
 
double eps = 1e-12;
#define dbg(x) cout<<#x<<" = "<<x<<"\n"
#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long

signed main() { WA();
    string a, b;
    int t = 0;
    while (getline(cin, a) && a != "#" && getline(cin, b)) {
        int n = sz(a), m = sz(b);
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        cout << "Case #" << ++t << ": you can visit at most " << dp[n][m] << " cities.\n";
    }
}