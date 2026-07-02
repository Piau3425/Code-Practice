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
    for (int n, m, t = 0; cin >> n >> m, n+m;) { cout << (t ? "\n" : "") << "Field #" << ++t << ":\n";
        vector<vector<char>> v(n, vector<char>(m));
        for (auto &i : v) for (auto &j : i) cin >> j;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == '*') cout << '*';
                else {
                    int cnt = 0;
                    for (int p = -1; p <= 1; p++) for (int q = -1; q <= 1; q++) cnt += i+p >= 0 && j+q >= 0 && i+p < n && j+q < m && v[i+p][j+q] == '*';
                    cout << cnt;
                }
            }
            cout << '\n';
        }
    }
}