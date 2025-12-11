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

vector<int> dep, cur;
vector<vector<int>> g, bu;
int n, m, s, t;

bool bfs() {
    fill(all(dep), -1); dep[s] = 0;
    queue<int> q; q.push(s);
    while (q.size()) { // u -> v
        int u = q.front(); q.pop();
        for (int v = 0; v < n*2; v++) if (g[u][v] && !~dep[v]) {
            dep[v] = dep[u]+1;
            q.push(v);
        }
    }
    return ~dep[t];
}

int dfs(int u, int mn) {
    if (!mn) return 0;
    if (u == t) return mn;

    for (int &v = cur[u]; v < n*2; v++) {
        if (dep[u]+1 == dep[v] && g[u][v]) {
            if (int go = dfs(v, min(mn, g[u][v]))) {
                g[u][v] -= go;
                g[v][u] += go;
                return go;
            }
        }
    }
    return 0;
}

int dinic() {
    int flow = 0;
    while (bfs()) {
        fill(all(cur), 0);
        while (int go = dfs(s, INF)) flow += go;
    }
    return flow;
}

signed main() { WA();
    for (; cin >> n >> m;) {
        g.assign(n*2, vector<int>(n*2, 0));
        dep.assign(n*2, 0);
        cur.assign(n*2, 0);
        for (int i = 0; i < n; i++) g[i][i+n] = 1;
        for (int k = m; k--;) {
            char c; int a, b;
            cin >> c >> a >> c >> b >> c;
            g[a+n][b] = INF;
            g[b+n][a] = INF;
        } bu = g;
        int ans = n;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                g = bu;
                s = i+n; t = j;
                ans = min(ans, dinic());
            }
        }
        cout << ans << '\n';
    }
}