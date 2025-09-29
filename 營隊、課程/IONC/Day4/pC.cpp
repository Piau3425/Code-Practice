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
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (auto &i : v) for (auto &j : i) cin >> j;
    map<int, vector<PII>> dots;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dots[v[i][j]].emplace_back(i, j);
        }
    }

    int ans = 1e9;
    for (auto [color, v] : dots) {
        if (v.size() < 550) {
            for (auto &i : v) for (auto &j : v) {
                if (i == j) continue;
                ans = min(ans, abs(i.fi-j.fi)+abs(i.se-j.se));
            }
        }
        else {
            queue<PII> q;
            vector<vector<int>> dis(n, vector<int>(n, -1));
            for (auto &i : v) {
                dis[i.fi][i.se] = 0;
                q.emplace(i.fi, i.se);
            }
            while (q.size()) {
                auto [x, y] = q.front(); q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + mx[i], ny = y + my[i];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                        if (~dis[nx][ny]) ans = min(ans, dis[nx][ny]+dis[x][y]+1);
                        else {
                            dis[nx][ny] = dis[x][y] + 1;
                            q.emplace(nx, ny);
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}