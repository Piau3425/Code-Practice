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

vector<vector<int>> g, gr;
vector<int> vis;
stack<int> order;
int t, ck;

void dfs1(int x) {
    vis[x] = 1;
    for (auto u : g[x]) if (!vis[u]) {
        vis[u] = 1;
        dfs1(u);
    }
    order.push(x);
}

void dfs2(int x) {
    vis[x] = t;
    for (auto u : gr[x]) if (!vis[u]) {
        dfs2(u);
    }
}

signed main() { WA();
    int n, m; cin >> n >> m;
    g.assign(n+1, vector<int>());
    gr.assign(n+1, vector<int>());
    while (m--) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        gr[b].pb(a);
    }
    vis.assign(n+1, 0);
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        dfs1(i);
    }
    t = 1, ck = 0;
    int cnt = 0;
    vis.assign(n+1, 0);
    while (order.size()) {
        if (!vis[order.top()]) {
            dfs2(order.top());
            t++;
            cnt++;
        }
        order.pop();
    }
    vis.erase(vis.begin());
    cout << cnt << '\n';
    for (auto &i : vis) cout << i << " \n"[&i == &vis.back()];
}