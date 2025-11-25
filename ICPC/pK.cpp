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

int mx[] = {0, 1, 1, 1, 0, -1, -1, -1}, my[] = {1, 1, 0, -1, -1, -1, 0, 1};

signed main() { WA();
    int n, m, k; cin >> n >> m >> k;
    vector<vector<char>> v(n, vector<char>(m));
    vector<int> cnt(10000001);
    for (auto &i : v) for (auto &j : i) cin >> j;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (!isdigit(v[i][j])) continue;
        cnt[v[i][j]-'0']++;
        for (int dir = 0; dir < 8; dir++) {
            char last = '_';
            int nx = i, ny = j, now = 0, buf = 1, cur = v[i][j]-'0';
            while (1) {
                nx += mx[dir], ny += my[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
                if (isdigit(v[nx][ny])) {
                    cur = cur*10+v[nx][ny]-'0';
                    if (now+buf*cur > 1000000) break;
                    cnt[now+buf*cur]++;
                }
                else {
                    if (last == '+' || last == '*') break;
                    if (v[nx][ny] == '+') now += cur*buf, cur = 0, buf = 1;
                    if (v[nx][ny] == '*') buf *= cur, cur = 0;
                }
                last = v[nx][ny];
            }
            
        }
    }
    for (int i; k--;) cin >> i, cout << cnt[i] << '\n';
}