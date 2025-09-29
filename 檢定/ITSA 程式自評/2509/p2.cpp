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
    int n, m;
    cin >> m >> n;
    vector<vector<int>> v(m, vector<int>(n)), c = v;
    for (auto &i : v) for (auto &j : i) cin >> j;
    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            int cnt = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int nx = x+i, ny = y+j;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && v[nx][ny]) cnt++;
                }
            }
            c[x][y] = (v[x][y] ? 9 : cnt);
        }
    }
    for (auto &i : c) for (auto &j : i) cout << j << " \n"[&j == &i.back()];
}