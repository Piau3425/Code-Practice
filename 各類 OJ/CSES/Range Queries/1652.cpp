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
    int n, q; cin >> n >> q;
    vector<vector<char>> v(n, vector<char>(n));
    for (auto &i : v) for (auto &j : i) cin >> j;
    vector<vector<int>> pre(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + (v[i-1][j-1] == '*');
        }
    }

    while (q--) {
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        cout << pre[y2][x2] - pre[y1-1][x2] - pre[y2][x1-1] + pre[y1-1][x1-1] << '\n';
    }
}