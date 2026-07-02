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
#define TIII tuple<int, int, int>

TIII mp[1005][1005][4];
bool vis[1005][1005][4];

signed main() { WA();
    int n, m; cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    int sx, sy, ex, ey;
    for (auto &i : v) for (auto &j : i) {
        cin >> j;
        if (j == 'S') sx = &i-v.data(), sy = &j-i.data();
        if (j == 'G') ex = &i-v.data(), ey = &j-i.data();
    }
    queue<TIII> q;
    int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int nx = sx+dx[i], ny = sy+dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != '#') q.push({nx, ny, i}), vis[nx][ny][i] = 1, mp[nx][ny][i] = {sx, sy, -1};
    }

    string dir = "DRUL";
    while (q.size()) {
        auto [x, y, last] = q.front(); q.pop();
        if (x == ex && y == ey) {
            cout << "Yes\n";
            string s;
            while (ex != sx || ey != sy) {
                s += dir[last];
                tie(ex, ey, last) = mp[ex][ey][last];
            }
            cout << string(s.rbegin(), s.rend());
            exit(0);
        }

        if (v[x][y] == 'o') {
            int nx = x+dx[last], ny = y+dy[last];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != '#' && !vis[nx][ny][last]) q.push({nx, ny, last}), mp[nx][ny][last] = {x, y, last}, vis[nx][ny][last] = 1;
        }
        else {
            for (int i = 0; i < 4; i++) {
                if (v[x][y] == 'x' && last == i) continue;
                int nx = x+dx[i], ny = y+dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != '#' && !vis[nx][ny][i]) q.push({nx, ny, i}), mp[nx][ny][i] = {x, y, last}, vis[nx][ny][i] = 1;
            }
        }
    }
    cout << "No";
}