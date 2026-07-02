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
#define sz 1+26+10+1

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
    string str; while (getline(cin, str)) {
        int sum = 0;
        g.assign(sz, vector<int>(sz, 0));
        dep.assign(sz, 0);
        cur.assign(sz, 0);
        do {
            int app = str[0]-'A'+1;
            sum += g[0][app] = str[1]-'0';
            for (int i = 3; i < str.size()-1; i++) g[app][str[i]-'0'+1+26] = 1;
        } while (getline(cin, str) && str.size());
        for (int i = 1; i <= 10; i++) g[26+i][sz-1] = 1;
        
        s = 0, t = sz-1;
        if (dinic() == sum) {
            string ans = string(10,'_');
            for (int i = 1; i <= 10; i++) {
                for (int j = 1; j <= 26; j++) if (g[26+i][j]) {
                    ans[i-1] = 'A'+j-1;
                    break;
                }
            }
            cout << ans << '\n';
        }
        else cout << "!\n";
    }
}