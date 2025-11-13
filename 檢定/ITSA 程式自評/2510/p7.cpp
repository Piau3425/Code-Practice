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

vector<vector<int>> v, vis;
int mx[] = {1, 0, -1, 0}, my[] = {0, 1, 0, -1}, n, m;

void dfs(int x, int y) {
    //cout << x << ' ' << y << '\n';
    for (int i = 0; i < 4; i++) {
        int nx = x+mx[i], ny = y+my[i];
        if (nx < n && nx >= 0 && ny < m & ny >= 0 && !v[nx][ny] && !vis[nx][ny]) vis[nx][ny] = 1, dfs(nx, ny);
    }
}

signed main() { WA();
    cin >> n >> m;
    v.assign(n, vector<int>(m)); vis = v;
    for (auto &i : v) for (auto &j : i) cin >> j;
    int x, y; cin >> x >> y;
    dfs(x, y);
    int flag = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (!v[i][j] && !vis[i][j]) flag = 1;
    if (flag) cout << "true\n";
    else cout << "false\n";
}