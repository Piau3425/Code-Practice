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

int mx[] = {0, 1, 0, -1}, my[] = {1, 0, -1, 0}, n, m;
vector<vector<char>> v;
vector<vector<int>> vis;

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x+mx[i], ny = y+my[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != '#' && !vis[nx][ny]) dfs(nx, ny);
    }
}

signed main() { WA();
    int cnt = 0; cin >> n >> m;
    v.assign(n, vector<char>(m));
    vis.assign(n, vector<int>(m));
    for (auto &i : v) for (auto &j : i) cin >> j;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '.' && !vis[i][j]) {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << '\n';
}