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

vector<int> vis;
vector<vector<int>> g, gt;

void dfs(vector<vector<int>> &vec, int v, vector<int> &output) {
    vis[v] = 1;
    for (auto &w : vec[v]) {
        if (!vis[w]) dfs(vec, w, output);
    }
    output.pb(v);
}

signed main() { WA();
    int n, m; cin >> n >> m;
    vector<int> coin(n+1), sk;
    vector<vector<int>> scc;
    for (int i = 1; i <= n; i++) cin >> coin[i];
    g.resize(n+1);
    gt.resize(n+1);
    while (m--) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        gt[b].pb(a);
    }
    vis.resize(n+1);
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(g, i, sk);
    reverse(all(sk));
    vis.assign(n+1, 0);
    int id = -1;
    vector<int> roots(n+1), sum(n+1, 0), all_root;
    for (auto &i : sk) {
        if (!vis[i]) {
            vector<int> comp;
            dfs(gt, i, comp);
            scc.pb(comp);
            int root = *min_element(all(comp));
            all_root.pb(root);
            for (auto &i : comp) {
                roots[i] = root;
                sum[root] += coin[i];
            }
        }
    }
    vector<unordered_set<int>> dag(n+1);
    for (int v = 1; v <= n; v++) {
        for (auto &u : g[v]) if (roots[v] != roots[u])
            dag[roots[v]].insert(roots[u]);
    }
    vector<int> w(n+1), dp(n+1);
    for (int u = 1; u <= n; u++) {
        for (auto &v : dag[u]) w[v]++;
    }
    queue<int> q;
    for (auto &i : all_root) {
        dp[i] = sum[i];
        if (!w[i]) q.push(i);
    }

    while (q.size()) {
        int u = q.front(); q.pop();
        for (auto &v : dag[u]) {
            dp[v] = max(dp[v], dp[u] + sum[v]);
            if (!(--w[v])) q.push(v);
        }
    }
    int ans = 0;
    for (auto &i : all_root) ans = max(ans, dp[i]);
    cout << ans;
}