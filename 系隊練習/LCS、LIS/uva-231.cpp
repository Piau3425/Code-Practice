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
    int n, m, T = 0;
    while (cin >> n,  ~n) {
        vector<int> a, b; a.pb(n);
        while (cin >> n, ~n) a.pb(n);
        int n = a.size();
        b = a; sort(all(b), greater<int>());
        n = a.size(); m = b.size();
        vector<vector<int>> v(n+1, vector<int>(m+1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i-1] == b[j-1]) v[i][j] = v[i-1][j-1] + 1;
                else v[i][j] = max(v[i-1][j], v[i][j-1]);
            }
        }
        if (T) cout << '\n';
        cout << "Test #" << ++T << ":\n  maximum possible interceptions: " << v[n][m] << '\n';
    }
}