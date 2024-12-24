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

vector<vector<int>> g;
vector<int> c;
int valid;

 void dfs(int v) {
    for (auto u : g[v]) {
        if (c[u]) {
            if (c[u] == c[v]) return void(valid = 0);
            continue;
        }
        c[u] = 3-c[v];
        dfs(u);
    }
}

signed main() { WA();
    int n, m, a, b;
    while (cin >> n >> m) {
        g.assign(n, vector<int>(0));
        c.assign(n, 0);
        while (m--) {
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }

        valid = 1;
        for (int i = 0; i < n; i++) if (!c[i]) c[i] = 1, dfs(i);
        if (valid) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
    }
}