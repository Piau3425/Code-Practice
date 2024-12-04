#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long

signed main() { WA();
    int n, m, sx, sy, ex, ey, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cin >> v[i][j];
        if (v[i][j] == 'A')  sy = i, sx = j;
        else if (v[i][j] == 'B') ey = i, ex = j;
    }

    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0)), par(n, vector<int>(m));
    q.push({sy, sx});
    vis[sy][sx] = 1;

    string s, dir = "RDLU";
    while (!q.empty()) {
        auto d = q.front(); q.pop();
        if (d.fi == ey && d.se == ex) {
            cout << "YES\n";
            while (v[ey][ex] != 'A') {
                int last = par[ey][ex];
                s += dir[last];
                ey -= dy[last];
                ex -= dx[last];
            }
            return cout << s.size() << '\n' << string(s.rbegin(), s.rend()), 0;
        }

        for (int mv = 0; mv < 4; mv++) {
            int ny = d.fi + dy[mv], nx = d.se + dx[mv];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && !vis[ny][nx] && v[ny][nx] != '#') {
                q.push({ny, nx});
                vis[ny][nx] = 1;
                par[ny][nx] = mv;
            }
        }
    }

    cout << "NO";
}