#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

int n, m, cnt, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
vector<string> v;
vector<vector<int>> vis;

void dfs(int x, int y, char num) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && (v[nx][ny] == num || v[nx][ny] == '*') && !vis[nx][ny]) {
            vis[nx][ny] = 1;
            cnt++;
            dfs(nx, ny, num);
            if (v[nx][ny] == '*') vis[nx][ny] = 0;
        }
    }
}

signed main() { WA();
    cin >> n;
    vector<PII> ans;
    v.assign(n, string());
    for (auto &i : v) cin >> i;
    m = v[0].size();
    vis.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] != '0' && v[i][j] != '*' && !vis[i][j]) {
                cnt = 1;
                vis[i][j] = 1;
                dfs(i, j, v[i][j]);
                ans.pb({cnt, v[i][j]-'0'});
            }
        }
    }
    sort(all(ans));
    for (auto i : ans) cout << i.se << ' ' << i.fi << '\n';
}