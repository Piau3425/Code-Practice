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
    int N, T, G = 0;
    while (cin >> N, N) {
        cin >> T;
        vector<int> t(N+1);
        for (int i = 1; i <= N-1; i++) cin >> t[i];
        int ht[T+1][N+1][2] = {};
        int k; cin >> k;
        while (k--) {
            int now; cin >> now;
            for (int i = 1; i <= N && now <= T; i++) {
                ht[now][i][0] = 1;
                now += t[i];
            }
        }
        cin >> k;
        while (k--) {
            int now; cin >> now;
            for (int i = N; i >= 1 && now <= T; i--) {
                ht[now][i][1] = 1;
                now += t[i-1];
            }
        }
        vector<vector<int>> dp(T+1, vector<int>(N+1, INF));
        dp[T][N] = 0;
        for (int i = T-1; i >= 0; i--) for (int j = 1; j <= N; j++) {
            dp[i][j] = dp[i+1][j] + 1;
            if (j < N && ht[i][j][0] && i + t[j] <= T) dp[i][j] = min(dp[i][j], dp[i+t[j]][j+1]);
            if (j > 1 && ht[i][j][1] && i + t[j-1] <= T) dp[i][j] = min(dp[i][j], dp[i+t[j-1]][j-1]);
        }
        if (dp[0][1] < INF) cout << "Case Number " << ++G << ": " << dp[0][1] << '\n';
        else cout << "Case Number " << ++G << ": impossible\n";
    }
}