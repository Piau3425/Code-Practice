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

vector<vector<int>> v;
vector<int> vis;
int flag = 1;

void dfs(int x) {
    for (auto u : v[x]) if (!vis[u]) {
        vis[u] = 3 - vis[x];
        dfs(u);
    }
    else if (flag) flag = vis[x] != vis[u];
}

signed main() { WA();
    int n, m; cin >> n >> m;
    v.resize(n+1);
    vis.resize(n+1);
    while (m--) {
        int a, b; cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            dfs(i);
        }
    }
    if (flag) {
        for (int i = 1; i <= n; i++) cout << vis[i] << ' ';
    }
    else cout << "IMPOSSIBLE\n";
}