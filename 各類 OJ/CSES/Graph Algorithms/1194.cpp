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

int mx[] = {1, 0, -1, 0}, my[] = {0, 1, 0, -1};

signed main() { WA();
    for (int n, m; cin >> n >> m;) {
        vector<vector<char>> v(n, vector<char>(m));
        vector<vector<int>> vis(n, vector<int>(m));
        queue<tuple<int, int, int>> q;
        int sx, sy;
        for (auto &i : v) for (auto &j : i) {
            cin >> j;
            int x  = &i-v.data(), y = &j-i.data();
            if (j == 'M') vis[x][y] = 1, q.push({-1, x, y});
            if (j == 'A') sx = x, sy = y;
        }
        vis[sx][sy] = 1; q.push({1, sx, sy});
        string ans, dir = "DRUL"; int flag = 0;
        map<int, int> mp; map<int, char> go;
        while (q.size()) {
            auto [type, x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x+mx[i], ny = y+my[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    if (~type) {
                        flag = 1;
                        q = {};
                        int now = x*m+y;
                        while (mp.find(now) != mp.end()) {
                            ans += go[now];
                            now = mp[now];
                        }
                        break;
                    }
                }
                else if (v[nx][ny] != '#' && !vis[nx][ny]) {
                    vis[nx][ny] = 1, q.push({type, nx, ny});
                    if (~type) {
                        mp[nx*m+ny] = x*m+y;
                        go[nx*m+ny] = dir[i];
                    }
                }
            }
        }
        if (flag) cout << "YES\n" << ans.size() << '\n' << string(ans.rbegin(), ans.rend()) << '\n';
        else cout << "NO\n";
    }
}