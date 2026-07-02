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
    int p = 1e9+7;
    vector<vector<int>> C(1001, vector<int>(1001)), dp = C;
    for (int i = 0, j; i <= 1000; i++) {
        for (C[i][0] = C[i][i] = 1, j = 1; j < i; j++) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % p;
    }
    
    dp[0][0] = 1;
    for (int i = 1; i <= 1000; i++) {
        dp[i][0] = dp[i-1][0]*i % p;
        for (int j = 1; j <= i; j++) dp[i][j] = (dp[i][j-1] - dp[i-1][j-1] + p) % p;
    }

    int t = 1, T; for (cin >> T; t <= T; t++) {
        int n, m, k; cin >> n >> m >> k;
        cout << "Case " << t << ": " << C[m][k] * dp[n-k][m-k] % p << '\n';
    }
}