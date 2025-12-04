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

int mx[] = {0, 1, 0, -1}, my[] = {1, 0, -1, 0}, n, m, sx, sy, ex, ey, cnt = 0;
vector<vector<char>> v;
vector<vector<int>> vis;
string ans, dir = "RDLU";

signed main() { WA();
    cin >> n >> m;
    v.assign(n, vector<char>(m));
    vis.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cin >> v[i][j];
        if (v[i][j] == 'A') sx = i, sy = j;
        if (v[i][j] == 'B') ex = i, ey = j;
    }
    queue<tuple<int, int>> q;
    vector<int> mp(n*m);
    vector<char> go(n*m);
    q.push({sx, sy});
    while (q.size()) {
        auto [x, y] = q.front(); q.pop();
        if (ex == x && ey == y) break;
        if (vis[x][y]) continue;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x+mx[i], ny = y+my[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != '#' && !vis[nx][ny]) {
                q.push({nx, ny});
                mp[nx*m+ny] = x*m+y;
                go[nx*m+ny] = dir[i];
            }
        }
    }
    int now = ex*m+ey;
    if (!mp[now]) return cout << "NO\n", 0;
    while (mp[now] != sx*m+sy) {
        ans += go[now];
        now = mp[now];
    }
    ans += go[now];
    cout << "YES\n" << ans.size() << '\n' << string(ans.rbegin(), ans.rend()) << '\n';
}