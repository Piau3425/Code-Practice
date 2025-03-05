#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define INF LONG_LONG_MAX/1000

signed main() { WA();
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n, vector<int>(n, INF));

    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        g[a][b] = g[b][a] = min(g[a][b], w);
    }

    for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        g[i][j] = g[j][i] = min(g[i][j], g[i][k] + g[k][j]);
    }
    for (int i = 0; i < n; i++) g[i][i] = 0;

    while (q--) {
        int a, b; cin >> a >> b;
        a--; b--;
        cout << (g[a][b] == INF ? -1 : g[a][b]) << '\n';
    }
}