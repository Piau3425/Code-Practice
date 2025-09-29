#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, k, a, b;
vector<vector<int>> g1(2*100000), g2(2*100000);
vector<int> vis(2*100000);
map<int, int> m1, m2;

void dfs(int v, vector<vector<int>> g, map<int, int> &mp) {
    for (auto u : g[v]) if (!vis[u]) {
        vis[u] = 1;
        mp[u]++;
        dfs(u, g, mp);
    }
}

signed main() {
    cin >> n >> m >> k;
    while (m--) {
        cin >> a >> b;
        g1[a].push_back(b);
        g1[b].push_back(a);
    }
    while (k--) {
        cin >> a >> b;
        g2[a].push_back(b);
        g2[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        int ans = 0;
        vis.clear(); m1.clear(); m2.clear();
        dfs(i, g1, m1);
        vis.clear();
        dfs(i, g2, m2);
        for (auto i : m1) if (m2[i.first]) ans++;
        cout << ans << ' ';
    }
}