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
    int T; cin >> T;
    for (int k = 1; k <= T; k++) {
        cout << "Case #" << k << ": ";
        int n, m, s, t; cin >> n >> m >> s >> t;
        vector<vector<PII>> g(n);
        vector<int> dis(n, INF);
        while (m--) {
            int a, b, w; cin >> a >> b >> w;
            g[a].pb({b, w});
            g[b].pb({a, w});
        }
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        pq.push({0, s}); dis[s] = 0;
        while (pq.size()) {
            auto [nowDist, nowID] = pq.top(); pq.pop();
            if (nowDist > dis[nowID]) continue;
            for (auto [toID, toDist] : g[nowID]) {
                if (dis[toID] > dis[nowID] + toDist) {
                    dis[toID] = dis[nowID] + toDist;
                    pq.push({dis[toID], toID});
                }
            }
        }

        if (dis[t] == INF) cout << "unreachable\n";
        else cout << dis[t] << '\n';
    }
}