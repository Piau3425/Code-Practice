#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long

signed main() { WA();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n+1, vector<int>(n+1, 0));

    for(int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        cin >> v[i][j];
        v[i][j] += v[i-1][j] + v[i][j-1] - v[i-1][j-1];
    }

    int sx, sy, ex, ey;
    while (m--) {
        cin >> sy >> sx >> ey >> ex;
        cout << v[ey][ex] - v[ey][sx-1] - v[sy-1][ex] + v[sy-1][sx-1] << '\n';
    }
}