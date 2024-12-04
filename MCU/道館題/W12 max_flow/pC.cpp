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

int n, m, sy, sx, dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};

signed main() { WA();
    queue<pair<int, int>> q;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cin >> v[i][j];
        if (v[i][j] == 'M') q.push({i, j});
        else if (v[i][j] == 'A') sy = i, sx = j;
    }

    vector<vector<int>> vis(n, vector<int>(m, 0)), par(n, vector<int>(m));
    q.push({sy, sx});
    vis[sy][sx] = 1;
    q.push({sy, sx});
    while (!q.empty()) {
        auto d = q.front(); q.pop();
        for (int mv = 0; mv < 4; mv++) {
            int ny = d.fi + dy[mv], nx = d.se + dx[mv];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) return void(s.insert({ny, nx}));
            else if (!vis[ny][nx] && v[ny][nx] != '#') {
                q.push({ny, nx});
                vis[ny][nx] = 1;
            }
        }
    }
}