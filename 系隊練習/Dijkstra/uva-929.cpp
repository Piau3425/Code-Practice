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
#define TIII tuple<int, int, int>

signed main() { WA();
    int t; for (cin >> t; t--;) {
        int n, m; cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        vector<vector<int>> w(n, vector<int>(m, INF));
        for (auto &i : v) for (auto &j : i) cin >> j;
        priority_queue<TIII, vector<TIII>, greater<TIII>> pq;
        pq.push({v[0][0], 0, 0}); w[0][0] = v[0][0];
        while (pq.size()) {
            auto [nowDis, nowX, nowY] = pq.top(); pq.pop();
            if (nowDis > w[nowX][nowY]) continue;
            if (nowX == n-1 && nowY == m-1) {
                cout << w[nowX][nowY] << '\n';
                break;
            }
            int mx[] = {0, 1, 0, -1}, my[] = {1, 0, -1, 0};
            for (int i = 0; i < 4; i++) {
                int nx = nowX + mx[i], ny = nowY + my[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (nowDis+v[nx][ny] < w[nx][ny]) {
                    w[nx][ny] = nowDis+v[nx][ny];
                    pq.push({w[nx][ny], nx, ny});
                }
            }
        }
    }
}