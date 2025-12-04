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

vector<vector<char>> v;
vector<vector<int>> vis;
string s;
int n, m, isfind, mx[] = {0, -1, 0, 1}, my[] = {1, 0, -1, 0};

void dfs(int x, int y, int k) {
    if (k == s.size()) return void(isfind = 1);

    for (int i = 0; i < 4; i++) {
        int nx = x + mx[i], ny = y + my[i];
        if (nx < n && nx >= 0 && ny < n && ny >= 0 && !vis[nx][ny] && v[nx][ny] == s[k]) {
            vis[nx][ny] = 1;
            dfs(nx, ny, k+1);
            vis[nx][ny] = 0;
        }
    }
}

signed main() {
    cin >> n >> m;
    v.resize(n, vector<char>(n));
    vis.assign(n, vector<int>(n, 0));
    for (auto &i : v) for (auto &j : i) cin >> j;

    while (m--) {
        cin >> s;
        isfind = 0;
        for (int i = 0; i < n && !isfind; i++) for (int j = 0; j < n && !isfind; j++) if (v[i][j] == s[0]) {
            vis[i][j] = 1;
            dfs(i, j, 1);
            vis[i][j] = 0;
        }

        if (isfind) cout << "Yes\n";
        else cout << "No\n";
    }
}