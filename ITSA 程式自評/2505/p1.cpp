#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int t; cin >> t;
    while (t--) {
        int n, m, l; cin >> n >> m >> l;
        vector<vector<int>> v(n, vector<int>(m));
        while (l--) {
            int r, c; cin >> r >> c; r--, c--;
            v[r][c] = 1;
            for (int i = -1; i <= 1; i++) for (int j = -1; j <= 1; j++) {
                int nr = r + i, nc = c + j;
                if ((!i || !j) && nr < n && nr >= 0 && nc < m && nc >= 0) v[nr][nc] = 1;
            }
        }
        int ck = 1;
        for (auto &i : v) if (count(all(i), 0)) ck = 0;
        if (ck) cout << "Y\n";
        else cout << "N\n";
    }
}