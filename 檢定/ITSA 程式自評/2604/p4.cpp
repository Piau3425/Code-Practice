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
    int n, m; cin >> n >> m;
    vector<vector<int>> pre(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        int x; cin >> x;
        pre[i][j] = x + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
    }
    while (m--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1] << '\n';
    }
}