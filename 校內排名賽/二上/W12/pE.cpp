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

int mx[] = {0, 1, 0, -1}, my[] = {1, 0, -1, 0};
int d[101][101][1<<10];

signed main() { WA();
    for (int n; cin >> n;) {
        memset(d, 0, sizeof(d));
        vector<vector<char>> v(n, vector<char>(n));
        for (auto &i : v) for (auto &j : i) cin >> j;
        queue<tuple<int, int, int>> q;
        for (int i = 0; i < (1<<10); i++) if (!!islower(v[0][0]) == ((i>>(tolower(v[0][0])-'a'))&1)) {
            d[0][0][i] = 1;
            q.push({0, 0, i});
        }
        int ans = -1;
        while (q.size()) {
            auto [x, y, mask] = q.front(); q.pop();
            if (x == n-1 && y == n-1) {
                ans = d[x][y][mask];
                break;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + mx[i], ny = y + my[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (!!islower(v[nx][ny]) != ((mask>>(tolower(v[nx][ny])-'a'))&1)) continue;
                if (!d[nx][ny][mask]) {
                    d[nx][ny][mask] = d[x][y][mask]+1;
                    q.push({nx, ny, mask});
                }
            }
        }
        cout << ans << '\n';
    }
}