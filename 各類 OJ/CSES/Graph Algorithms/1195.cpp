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

vector<int> Dijkstra(int start, vector<vector<PII>> &g) {
    vector<int> vis(g.size()), dis(g.size(), INF);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, start}); dis[start] = 0;
    while (pq.size()) {
        auto [nowDist, nowID] = pq.top(); pq.pop();
        if (vis[nowID]) continue;
        vis[nowID] = 1;
        for (auto [toID, toDist] : g[nowID]) {
            if (dis[toID] > dis[nowID] + toDist) {
                dis[toID] = dis[nowID] + toDist;
                pq.push({dis[toID], toID});
            }
        }
    }
    return dis;
}

signed main() { WA();
    int n, m; cin >> n >> m;
    vector<vector<PII>> g(n+1), rg(n+1);
    vector<tuple<int, int, int>> e;
    while (m--) {
        int a, b, w; cin >> a >> b >> w;
        g[a].pb({b, w});
        rg[b].pb({a, w});
        e.pb({w, a, b});
    }

    vector<int> dis1 = Dijkstra(1, g), dis2 = Dijkstra(n, rg);
    int mn = INF;
    for (auto [w, a, b] : e) {
        if (dis1[a] != INF && dis2[b] != INF) mn = min((w>>1) + dis1[a] + dis2[b], mn);
    }
    cout << mn << '\n';
}