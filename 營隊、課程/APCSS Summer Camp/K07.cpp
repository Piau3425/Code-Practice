#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a, b;
vector<vector<int>> g;
vector<int> vis, ans;

void dfs(int v) {
    for (auto u : g[v]) if (!vis[u]) {
        ans.push_back(u);
        vis[u] = 1;
        dfs(u);
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

    int x;
    cin >> x;
    vis[x] = 1;
    ans.push_back(x);
    dfs(x);

    sort(ans.begin(), ans.end());
    for (auto &i : ans) cout << i << " \n"[&i == &ans.back()];
}