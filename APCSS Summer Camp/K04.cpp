#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a, b;
bool valid = true;
vector<vector<int>> g;
vector<int> c;

void dfs(int v) {
    for (auto u : g[v]) {
        if (c[u]) {
            if (c[u] == c[v]) valid = false;
            continue;
        }
        c[u] = 3 - c[v];
        dfs(u);
    }
}

signed main() {
    cin >> n >> m;
    g.resize(n+1); c.resize(n+1, 0);
    while (m--) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) if (!c[i]) {
        c[i] = 1;
        dfs(i);
    }

    if (valid) for (int i = 1; i <= n; i++) cout << (i-1 ? " " : "") << c[i];
    else cout << "IMPOSSIBLE";
}