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
int n, m, s, t, k;

bool bfs() {
    fill(all(dep), -1); dep[s] = 0;
    queue<int> q; q.push(s);
    while (q.size()) { // u -> v
        int u = q.front(); q.pop();
        for (int v = 0; v < n+m+2; v++) if (g[u][v] && !~dep[v]) {
            dep[v] = dep[u]+1;
            q.push(v);
        }
    }
    return ~dep[t];
}

int dfs(int u, int mn) {
    if (!mn) return 0;
    if (u == t) return mn;

    for (int &v = cur[u]; v < n+m+2; v++) {
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
    for (; cin >> n >> m >> k;) {
        g.assign(n+m+2, vector<int>(n+m+2, 0));
        dep.assign(n+m+2, 0);
        cur.assign(n+m+2, 0);
        for (int i = 1; i <= n; i++) g[0][i] = 1;
        for (int i = 1; i <= m; i++) g[n+i][n+m+1] = 1;
        while (k--) {
            int a, b; cin >> a >> b;
            g[a][n+b] = 1;
        }
        s = 0, t = n+m+1;
        cout << dinic() << '\n';

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) if (g[n+j][i]) { 
                cout << i << ' ' << j << '\n';
                break; 
            }
        }
    }
}