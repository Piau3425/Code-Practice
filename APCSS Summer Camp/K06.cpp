#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a, b;
vector<vector<int>> g;
vector<int> vis, in_stk;

void dfs(int v) {
    in_stk[v] = 1;
    for (auto u : g[v]) {
        if (vis[u]) {
            if (!in_stk[u]) continue;
            cout << "YES";
            exit(0);
        }

        vis[u] = 1;
        dfs(u);
    }
    in_stk[v] = 0;
}

signed main() {
    cin >> n >> m;
    g.resize(n+1); vis.resize(n+1, 0); in_stk.resize(n+1, 0);
    while (m--) {
        cin >> a >> b;
        g[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) if (!vis[i]) {
        vis[i] = 1;
        dfs(i);
    }

    cout << "NO";
}