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

int mx[] = {1, 0, -1, 0}, my[] = {0, 1, 0, -1};

signed main() { WA();
    int t;
    for (cin >> t; t--;) {
        int n, m; cin >> n >> m;
        vector<vector<char>> v(n, vector<char>(m));
        vector<vector<int>> vis(n, vector<int>(m));
        queue<tuple<int, int, int, int>> q;
        int sx, sy;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'J') sx = i, sy = j;
            else if (v[i][j] == 'F') q.push({i, j, 1, 0});
        }
        q.push({sx, sy, 0, 1});
        int ans = -1;
        while (q.size()) {
            auto [x, y, isFire, dis] = q.front(); q.pop();
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            if ((!x || !y || x == n-1 || y == m-1) && !isFire) {
                ans = dis;
                break;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x+mx[i], ny = y+my[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != '#' && !vis[nx][ny]) {
                    if (isFire) q.push({nx, ny, 1, 0});
                    else q.push({nx, ny, 0, dis+1});
                }
            }
        }
        if (~ans) cout << ans << '\n';
        else cout << "IMPOSSIBLE\n";
    }
}