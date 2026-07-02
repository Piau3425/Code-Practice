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
#define sz n*2+2

vector<int> dep, cur;
vector<vector<int>> g, bu;
int n, m, s, t, k;

bool bfs() {
    fill(all(dep), -1); dep[s] = 0;
    queue<int> q; q.push(s);
    while (q.size()) { // u -> v
        int u = q.front(); q.pop();
        for (int v = 0; v < sz; v++) if (g[u][v] && !~dep[v]) {
            dep[v] = dep[u]+1;
            q.push(v);
        }
    }
    return ~dep[t];
}

int dfs(int u, int mn) {
    if (!mn) return 0;
    if (u == t) return mn;

    for (int &v = cur[u]; v < sz; v++) {
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
    while (cin >> n) {
        int x;
        g.assign(sz, vector<int>(sz, 0));
        dep.assign(sz, 0);
        cur.assign(sz, 0);
        for (int i = 1; i <= n; i++) {
            cin >> x;
            g[i][n+i] = x;
        }
        int m;
        for (cin >> m; m--;) {
            int i, j, c; cin >> i >> j >> c;
            g[n+i][j] = c;
        }
        int a, b; cin >> a >> b;
        while (a--) {
            cin >> x;
            g[0][x] = INF;
        }
        while (b--) {
            cin >> x;
            g[n+x][sz-1] = INF;
        }
        s = 0, t = sz-1;
        cout << dinic() << '\n';
    }
}