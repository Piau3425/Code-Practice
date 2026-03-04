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

vector<int> anc, val;

int Find(int x) {
    return anc[x] == x ? x : anc[x] = Find(anc[x]);
}

void Union(int u, int v) {
    if ((u = Find(u)) != (v = Find(v))) return void((anc[u] = v, val[v] += val[u]));
}

signed main() { WA();
    int t;
    for (cin >> t; t--;) {
        int n, m; cin >> n >> m;
        vector<vector<int>> w(n-1, vector<int>(m)), v(n, vector<int>(m-1));
        for (auto &i : w) for (auto &j : i) cin >> j;
        for (auto &i : v) for (auto &j : i) cin >> j;

        int faces = (n-1)*(m-1);
        anc.assign(faces+1, 0); iota(all(anc), 0);
        val.assign(faces+1, 0);

        for (int i = 0; i < n-1; i++) for (int j = 0; j < m-1; j++) val[i*(m-1)+j+1] = w[i][j] - w[i][j+1] + v[i][j] - v[i+1][j];

        for (int i = 0; i < n-1; i++) {
            string s; cin >> s;
            for (int j = 0; j < m; j++) if (s[j] == '0') Union(j == 0 ? 0 : i*(m-1)+j, j == m-1 ? 0 : i*(m-1)+j+1);
        }
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < m-1; j++) if (s[j] == '0') Union(i == 0 ? 0 : (i-1)*(m-1)+j+1, i == n-1 ? 0 : i*(m-1)+j+1);
        }

        int ans = 0, zeroRoot = Find(0);
        for (int i = 1; i <= faces; i++) if (Find(i) == i && i != zeroRoot && val[i] > 0) ans += val[i];
        cout << ans << '\n';
    }
}