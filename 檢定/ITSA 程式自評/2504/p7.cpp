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

int n, cnt = 0, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
vector<vector<char>> v;
vector<vector<int>> vis;

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && v[nx][ny] == '0' && !vis[nx][ny]) {
            vis[nx][ny] = 1;
            dfs(nx, ny);
        }
    }
}

signed main() { WA();
    cin >> n;
    v.assign(n, vector<char>(n));
    vis.assign(n, vector<int>(n, 0));
    for (auto &i : v) for (auto &j : i) cin >> j;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (v[i][j] == '0' && !vis[i][j]) {
            dfs(i, j);
            cnt++;
        }
    }
    cout << cnt;
}