#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

int sx, sy, ex, ey, m, n, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
vector<vector<int>> v, vis;

void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny >= 0 && ny < m && nx >= 0 && nx < n && v[ny][nx] == 0 && !vis[ny][nx]) {
            vis[ny][nx] = 1;
            dfs(ny, nx);
        }
    }
}

signed main() { WA();
    cin >> m >> n;
    v.assign(m, vector<int>(n, 0));
    vis.assign(m, vector<int>(n, 0));
    for (auto &i : v) for (auto &j : i) cin >> j;
    cin >> sy >> sx >> ey >> ex;
    dfs(sy, sx);
    if (vis[ey][ex]) cout << "true";
    else cout << "false";
}