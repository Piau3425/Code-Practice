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
    int n;
    map<char, int> mp = {
        {'R', 1}, {'Y', 2}, {'B', 4},
        {'W', 0}
    };
    map<int, char> gg = {
        {1, 'R'}, {2, 'Y'}, {4, 'B'},
        {3, 'O'},  {5, 'P'}, {6, 'G'},
        {7, 'D'}, {0, 'W'}
    };
    for (cin >> n; n--;) {
        int m, k; cin >> m >> k;
        vector<vector<int>> v(m, vector<int>(m)), t;
        for (auto &i : v) for (auto &j : i) {
            char c; cin >> c;
            j = mp[c];
        }
        while (k--) {
            t = v;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    for (int x = -1; x <= 1; x++) {
                        for (int y = -1; y <= 1; y++) {
                            if (x && y) continue;
                            if (i+x < 0 || i+x >= m || j+y < 0 || j+y >= m) continue;
                            v[i][j] |= t[i+x][j+y];
                        }
                    }
                }
            }
        }
        for (auto &i : v) {
            for (auto &j : i) {
                cout << gg[j];
            }
            cout << '\n';
        }
        if (n) cout << '\n';
    }
}