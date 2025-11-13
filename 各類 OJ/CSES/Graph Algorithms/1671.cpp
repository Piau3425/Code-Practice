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
    int n, m; cin >> n >> m;
    vector<vector<PII>> g(n+1);
    while (m--) {
        int a, b, w; cin >> a >> b >> w;
        g[a].pb({b, w});
    }

    vector<int> vis(n+1), dis(n+1, INF);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, 1}); dis[1] = 0;
    while (pq.size()) {
        auto [nowDist, nowID] = pq.top(); pq.pop();
        if (vis[nowID]) continue;
        vis[nowID] = 1;
        //dis[nowID] = nowDist;
        for (auto &[toID, toDist] : g[nowID]) {
            if (dis[nowID]+toDist < dis[toID]) {
                dis[toID] = dis[nowID] + toDist;
                pq.push({dis[toID], toID});
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << dis[i] << ' ';
}