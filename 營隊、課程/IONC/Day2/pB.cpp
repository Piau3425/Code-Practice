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
    int n, m;
    while (cin >> n >> m) {
        vector<vector<PII>> g(n+m+1);
        for (int route = 1; route <= m; route++) {
            int c, k, now, last; cin >> c >> k >> last;
            g[last].pb({last+route, c});
            g[last+route].pb({last, 0});
            while (m--) {
                cin >> now;
                g[now].pb({now+n, c});
                g[last+n].pb({now+route, 0});
                g[now+n].pb({now, 0});
                last = now;
            }
        }
        vector<int> vis(n+m+1), dis(n+m+1, INF);
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        dis[1] = 0; pq.push({dis[1], 1});
        while (pq.size()) {
            auto [d, node] = pq.top(); pq.pop();
            if (vis[node]) continue;
            vis[node] = 1;
            cout << node << '\n';
            for (auto [to_node, to_dis] : g[node]) {
                if (dis[node] + to_dis < dis[to_node]) {
                    dis[to_node] = dis[node] + to_dis;
                    pq.push({dis[to_node], to_node});
                }
            }
        }
        for (int i = 1; i <= 9998; i++) cout << (dis[i] == INF ? -1 : dis[i]) << " \n"[i==n];
    }
}