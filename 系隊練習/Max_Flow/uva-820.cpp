#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long   

int n, s, e, t, a, b, w;
vector<vector<int>> g;
vector<int> vis, par;

bool BFS() {
    queue<int> q;
    vis.assign(n+1, 0); par.assign(n+1, 0);
    q.push(s);
    while (q.size()) {
        int now = q.front(); q.pop();
        if (now == e) return true;
        for (int i = 1; i <= n; i++) if (g[now][i] && !vis[i]) {
            vis[i] = 1;
            par[i] = now;
            q.push(i);
        }
    }
    return false;
}

signed main() { WA();
    int c = 0;
    while (cin >> n, n) {
        g.assign(n+1, vector<int>(n+1, 0));
        
        cin >> s >> e >> t;
        while (t--) {
            cin >> a >> b >> w;
            g[a][b] += w;
            g[b][a] += w;
        }

        int ans = 0;
        while (BFS()) {
            int now = e, mnF = INF;
            while (now != s) {
                mnF = min(mnF, g[par[now]][now]);
                now = par[now];
            }
            now = e;
            while (now != s) {
                g[par[now]][now] -= mnF;
                g[now][par[now]] += mnF;
                now = par[now];
            }
            ans += mnF;
        }
        cout << "Network " << ++c << "\nThe bandwidth is " << ans << ".\n\n";
    }
}