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
        for (int v = 0; v < n; v++) if (g[u][v] && !~dep[v]) {
            dep[v] = dep[u]+1;
            q.push(v);
        }
    }
    return ~dep[t];
}

int dfs(int u, int mn) {
    if (!mn) return 0;
    if (u == t) return mn;

    for (int &v = cur[u]; v < n; v++) {
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
        g.assign(n, vector<int>(n, 0));
        dep.assign(n, 0);
        cur.assign(n, 0);
        while (m--) {
            int a, b, c; cin >> a >> b >> c;
            a--, b--, g[a][b] += c;
        }
        s = 0, t = n-1;
        cout << dinic() << '\n';
    }
}