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

int n, m;

void dfs(int x, int y, vector<vector<char>> &v, vector<vector<int>> &vis) {
    vis[x][y] = 1;
    for (int i = -1; i <= 1; i++) for (int j = -1; j <= 1; j++) if (x+i < n && x+i >= 0 && y+j < m && y+j >= 0 && !vis[x+i][y+j] && v[x+i][y+j] == '@') dfs(x+i, y+j, v, vis);
}

signed main() { WA();
    for (int cnt; cin >> n >> m, n+m; cout << cnt << '\n') {
        cnt = 0;
        vector<vector<char>> v(n, vector<char>(m));
        vector<vector<int>> vis(n, vector<int>(m));
        for (auto &i : v) for (auto &j : i) cin >> j;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (!vis[i][j] && v[i][j] == '@') dfs(i, j, v, vis), cnt++;
    }
}