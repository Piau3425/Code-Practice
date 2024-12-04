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
    int n, m, ans = 0, dy[] = {1, 0, -1, 0}, dx[] = {0, 1, 0, -1};
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (auto &i : g) for (auto &j : i) cin >> j;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (g[i][j] == '.' && !vis[i][j]) {
        ans++;
        //cout << i << ' ' << j << '\n';
        queue<pair<int, int>> q;
        q.push({i, j});
        while (q.size()) {
            auto now = q.front(); q.pop();
            for (int mv = 0; mv < 4; mv++) {
                int ny = now.fi + dy[mv], nx = now.se + dx[mv];
                if (ny >= 0 && ny < n && nx >= 0 && nx < m && !vis[ny][nx] && g[ny][nx] == '.') {
                    q.push({ny, nx});
                    vis[ny][nx] = 1;
                }
            }
        }
    }
    cout << ans;
}