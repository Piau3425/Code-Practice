#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>
#define TIII tuple<int, int, int>

template<typename T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int mx[] = {1, 2, 2, 1, -1, -2, -2, -1}, my[] = {-2, -1, 1, 2, 2, 1, -1, -2};

signed main() { WA();
    int n; for (cin >> n; n--;) {
        int r, c; cin >> r >> c;
        vector<vector<char>> v(r, vector<char>(c));
        for (auto &i : v) for (auto &j : i) cin >> j;
        vector<vector<int>> vis(r, vector<int>(c));
        int sx, sy, ex, ey;
        for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
            if (v[i][j] == 'Z') {
                for (int k = 0; k < 8; k++) if (int nx = i+mx[k], ny = j+my[k]; nx >= 0 && nx < r && ny >= 0 && ny < c) vis[nx][ny] = -1;
            }
            if (v[i][j] == 'A') sx = i, sy = j;
            if (v[i][j] == 'B') ex = i, ey = j;
        }

        queue<TIII> que; int ans = -1;
        for (que.push({sx, sy, 0}); que.size();) {
            auto [x, y, step] = que.front(); que.pop();
            //cout << x << ' ' << y << ' ' << step << '\n';
            if (x == ex && y == ey) {
                ans = step;
                break;
            }
            for (int p = -1; p <= 1; p++) for (int q = -1; q <= 1; q++) if (int nx = x+q, ny = y+p; (p || q) && nx >= 0 && nx < r && ny >= 0 && ny < c && v[nx][ny] != 'Z' && (!vis[nx][ny] || !~vis[nx][ny] && (v[nx][ny] == 'A' || v[nx][ny] == 'B'))) vis[nx][ny] = 1, que.push({nx, ny, step+1});
        }
        if (~ans) cout << "Minimal possible length of a trip is " << ans << '\n';
        else cout << "King Peter, you can't go now!\n";
    }
}