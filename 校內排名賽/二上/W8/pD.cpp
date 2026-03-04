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

signed main() { WA();
    int n, m, k;
    while (cin >> n >> m >> k, n+m+k) {
        vector<vector<char>> v(n, vector<char>(m));
        vector<vector<int>> g(n, vector<int>(m));
        for (auto &i : v) for (auto &j : i) cin >> j;
        int x = 0, y = k-1, step = 1;
        while (x >= 0 && x < n && y >= 0 && y < m) {
            if (g[x][y]) break;
            g[x][y] = step;
            if (v[x][y] == 'N') x--;
            else if (v[x][y] == 'S') x++;
            else if (v[x][y] == 'E') y++;
            else y--;
            step++;
        }
        if (x >= 0 && x < n && y >= 0 && y < m && g[x][y]) cout << g[x][y]-1 << " step(s) before a loop of " << step-g[x][y] << " step(s)\n";
        else cout << step-1 << " step(s) to exit\n";
    }
}