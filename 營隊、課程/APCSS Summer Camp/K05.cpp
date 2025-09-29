#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a, b;
vector<vector<int>> g;
vector<int> vis;

void dfs(int v, int p) {
    for (auto u : g[v]) {
        if (u == p) continue;
        if (vis[u]) {
            cout << "YES";
            exit(0);
        }
        vis[u] = 1;
        dfs(u, v);
    }
}

signed main() {

    cin >> n >> m;
    g.resize(n+1); vis.resize(n+1, 0);
    while (m--) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) if (!vis[i]) {
        vis[i] = 1;
        dfs(i, 0);
    }

    cout << "NO";
}