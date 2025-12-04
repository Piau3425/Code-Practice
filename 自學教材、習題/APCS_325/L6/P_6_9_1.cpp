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
        vector<int> w(n+1), p(n+1), dp(total+1);
        for (int i = 1; i <= n; i++) cin >> w[i];
        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) for (int j = total; j >= w[i]; j--) 
            dp[j] = max(dp[j-w[i]]+p[i], dp[j]);
            //if (dp[j-w[i]] + p[i] > dp[j]) dp[j] = dp[j-w[i]] + p[i];
        cout << dp[total];
    }