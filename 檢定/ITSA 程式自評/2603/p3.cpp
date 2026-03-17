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
    vector<vector<char>> v(8, vector<char>(8));
    for (auto &i : v) for (auto &j : i) cin >> j;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int flag = 0;
            for (int n = -1; n <= 1; n++) {
                for (int m = -1; m <= 1; m++) {
                    int nx = i+n, ny = j+m;
                    if (!n && !m) continue;
                    if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && v[i][j] == v[i+n][j+m]) flag = 1;
                }
            }
            if (flag) cout << '(' << i << ',' << j << ")\n";
        }
    }
}