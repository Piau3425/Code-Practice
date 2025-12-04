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
    for (int n; cin >> n;) {
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for (int i = 1, x; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> x;
                v[i][j] = x + v[i-1][j] - v[i-1][j-1] + v[i][j-1];
            }
        }

        int ans = -INF;
        for (int sx = 1; sx < n; sx++) for (int sy = 1; sy < n; sy++)
        for (int ex = sx+1; ex <= n; ex++) for (int ey = sy+1; ey <= n; ey++)
        ans = max(ans, v[ex][ey]-v[ex][sy-1]-v[sx-1][ey]+v[sx-1][sy-1]);

        cout << ans << '\n';
    }
}