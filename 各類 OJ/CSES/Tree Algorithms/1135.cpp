#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

vector<int> dep;
vector<vector<int>> par, v;

void dfs(int x, int u) {
    par[0][x] = u;
    for (auto &i : v[x]) {
        if (i == u) continue;
        dep[i] = dep[x]+1;
        dfs(i, x);
    }
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int i = 19; i >= 0; i--) if (dep[par[i][a]] >= dep[b]) a = par[i][a];
    if (a == b) return a;
    for (int i = 19; i >= 0; i--) if (par[i][a] != par[i][b]) a = par[i][a], b = par[i][b];
    return par[0][a];
}

signed main() { WA();
    int n, q; cin >> n >> q;
    int k = n-1;
    v.resize(n+1);
    while (k--) {
        int a, b; cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    par.resize(20, vector<int>(n+1));
    dep.resize(n+1);
    dfs(1, 1);
    for (int i = 1; i < 20; i++) for (int j = 1; j <= n; j++) {
        par[i][j] = par[i-1][par[i-1][j]];
    }

    while (q--) {
        int a, b; cin >> a >> b;
        cout << dep[a] + dep[b] - 2*dep[lca(a, b)] << '\n';
    }
}