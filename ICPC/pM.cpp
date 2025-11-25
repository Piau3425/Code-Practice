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

signed main() { WA();
    int n, m, k; cin >> n >> m >> k;
    vector<int> v(n+1);
    vector<vector<int>> g(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    while (m--) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    queue<PII> q; vector<int> ans(k+1), vis(n+1);
    q.push({1, 0}); int cnt = 0;
    while (q.size()) {
        auto [id, d] = q.front(); q.pop();
        if (vis[id]) continue;
        vis[id] = 1;
        ans[v[id]] = d;
        for (auto &u : g[id]) q.push({u, d+1});
    }
    for (int i = 1; i <= k; i++) cout << ans[i] << ' ';
}