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

signed main() { WA();
    for (int n; cin >> n;) {
        vector<vector<char>> v(n, vector<char>(n));
        vector<vector<int>> vis(n, vector<int>(n));
        for (auto &i : v) for (auto &j : i) cin >> j;
        queue<tuple<int, int, int>> q;
        q.push({1, 1, 1});
        string ans = "No solution!\n";
        while (q.size()) {
            auto &[x, y, w] = q.front(); q.pop();
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            if (x == n-2 && y == n-2) {
                ans = to_string(w);
                break;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x+mx[i], ny = y+my[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && v[nx][ny] != '#') q.push({nx, ny, w+1});
            }
        }
        cout << ans << '\n';
    }
}