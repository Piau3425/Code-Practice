#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, ans = -1e9;
    while (cin >> n) {
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for (int i = 1, tmp; i <= n; i++) for (int j = 1; j <= n; j++) {
                cin >> tmp;
                v[i][j] = tmp + v[i-1][j] - v[i-1][j-1] + v[i][j-1];
        }

        for (int sx = 1; sx < n; sx++) for (int sy = 1; sy < n; sy++)
            for (int ex = sx+1; ex <= n; ex++) for (int ey = sy+1; ey <= n; ey++)
                ans = max(ans, v[ex][ey]-v[ex][sy-1]-v[sx-1][ey]+v[sx-1][sy-1]);

        cout << ans << '\n';
    }
}