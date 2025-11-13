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
    string a, b; int n, m;
    while (cin >> n >> a >> m >> b) {
        vector<vector<int>> v(n+1, vector<int>(m+1, INF)); v[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                v[i][j] = min({v[i-1][j], v[i-1][j-1], v[i][j-1]})+1;
                if (a[i-1] == b[j-1]) v[i][j] = min(v[i][j], v[i-1][j-1]);
            }
        }
        cout << v[n][m] << '\n';
    }
}