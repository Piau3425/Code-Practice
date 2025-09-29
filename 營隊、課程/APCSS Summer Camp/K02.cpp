#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a, b;
vector<vector<int>> g;
vector<int> vis, ans;

void dfs(int x) {
    for (auto i : g[x]) if (!vis[i]) {
        vis[i] = 1;
        dfs(i);
    }
}

signed main() { ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    g.resize(n+1);
    vis.resize(n+1, 0);
    while (m--) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) if (!vis[i]) {
        ans.push_back(i);
        vis[i] = 1;
        dfs(i);
    }

    cout << ans.size() -1 << '\n';
    for (int i = 1; i < ans.size(); i++) cout << ans[0] << ' ' << ans[i] << '\n';
}