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
typedef pair<int, int> PII;

int n, m, ismon, sy, sx, dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};
vector<vector<char>> v;
vector<vector<int>> dis;

void BFS(int y, int x) {
    queue<PII> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> par(n, vector<int>(m));
    string s, dir = "RDUL";
    q.push({y, x});
    while (!q.empty()) {
        auto d = q.front(); q.pop();
        for (int mv = 0; mv < 4; mv++) {
            int ny = d.fi + dy[mv], nx = d.se + dx[mv];
            if (ny >= n || ny < 0 || nx >= m || nx < 0) {
                if (ismon) {
                    //dis[d.fi][s.se] = min(dis[d.fi][d.se], )
                }
                else {
                    while (d.fi != sy || d.se != sx) {
                        int last = par[d.fi][d.se];
                        s += dir[last];
                        d.fi -= dy[last];
                        d.se -= dx[last];
                    }
                    cout << "YES\n" << sz(s) << '\n' << string(s.rbegin(), s.rend());
                    exit(0);
                }
                break;
            }
            else if (!vis[ny][nx] && v[ny][nx] != '#') {
                q.push({ny, nx});
                vis[ny][nx] = 1;
                par[ny][nx] = mv;
            }
        }
    }
}

signed main() { WA();
    cin >> n >> m;
    v.resize(n, vector<char>(m));
    dis.assign(n, vector<int>(n, 0));
    vector<PII> mons;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cin >> v[i][j];
        if (v[i][j] == 'M') mons.push_back({i, j});
        else if (v[i][j] == 'A') sy = i, sx = j;
    }

    ismon = 1;
    for (auto mon : mons) {
        BFS(mon.fi, mon.se);
    }

    ismon = 0;
    BFS(sy, sx);

    cout << "NO\n";
}