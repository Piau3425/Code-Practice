#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
vector<int> vis;
vector<vector<int>> g;

void dfs(int v) {
    for (auto u : g[v]) {
        if (vis[u]) continue;
        vis[u] = 1;
        dfs(u);
    }
}

signed main() {
    int t = 0;
    while (cin >> n >> m, n+m) {
        g.clear(); vis.clear();
        g.resize(n+1); vis.resize(n+1, 0);
        while (m--) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            ans++;
            vis[i] = 1;
            dfs(i);
        }

        cout << "Case " << ++t << ": " << ans << '\n';
    }
}