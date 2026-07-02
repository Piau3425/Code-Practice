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
    int m, n; cin >> m >> n;
    vector<vector<int>> v(m, vector<int>(n));
    for (auto &row : v) for (auto &x : row) cin >> x;
    int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;

    vector<vector<int>> vis(m, vector<int>(n, 0));
    queue<PII> q;
    q.push({sx, sy}); vis[sx][sy] = 1;

    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    bool ok = false;
    while (q.size()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        if (x == ex && y == ey) {
            ok = true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !v[nx][ny] && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    if (ok) cout << "true\n";
    else cout << "false\n";
}