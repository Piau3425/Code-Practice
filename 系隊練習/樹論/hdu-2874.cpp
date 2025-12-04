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

vector<int> dep, dis;
vector<vector<int>> par;
vector<vector<PII>> v;

void dfs(int x, int u) {
    par[0][x] = u;
    for (auto &i : v[x]) {
        if (i.fi == u) continue;
        dep[i.fi] = dep[x]+1;
        dis[i.fi] = dis[x]+i.se;
        dfs(i.fi, x);
    }
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int i = 19; i >= 0; i--) if (dep[par[i][a]] >= dep[b]) a = par[i][a];
    if (a == b) return a;
    for (int i = 19; i >= 0; i--) if (par[i][a] != par[i][b]) a = par[i][a], b = par[i][b];
    if (par[0][a] != par[0][b]) return -1;
    else return par[0][a];
}

signed main() { WA();
    int n, m, c;
    while (cin >> n >> m >> c) {
        v.resize(n+1);
        par.resize(20, vector<int>(n+1));
        dep.resize(n+1);
        dis.resize(n+1);
        while (m--) {
            int a, b, w;
            cin >> a >> b >> w;
            v[a].pb({b, w});
            v[b].pb({a, w});
        }

        for (int i = 1; i <= n; i++) if (!par[0][i]) dep[i] = 0, dis[i] = 0, dfs(i, i);
        for (int i = 1; i < 20; i++) for (int j = 1; j <= n; j++) {
            par[i][j] = par[i-1][par[i-1][j]];
        }
        while (c--) {
            int a, b; cin >> a >> b;
            int k = lca(a, b);
            if (~k) cout << dis[a] + dis[b] - 2*dis[k] << '\n';
            else cout << "Not connected\n";
        }
        v.clear(); par.clear(); dep.clear(); dis.clear();
    }
}