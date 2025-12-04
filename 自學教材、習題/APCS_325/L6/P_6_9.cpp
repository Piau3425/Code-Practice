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
        int n, total; cin >> n >> total;
        vector<vector<int>> dp(n+1, vector<int>(total+1));
        vector<int> w(n+1), p(n+1);
        for (int i = 1; i <= n; i++) cin >> w[i];
        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < w[i]; j++) dp[i][j] = dp[i-1][j];
            for (int j = w[i]; j <= total; j++) dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+p[i]);
        }
        /*
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= total; j++) {
                if (j == 0) cout << setw(3) << p[i];
                else {
                    if (i == 0) cout << setw(3) << j;
                    else cout << setw(3) << dp[i][j];
                }
            }
            cout << '\n';
        }
        */
        cout << dp[n][total];
    }