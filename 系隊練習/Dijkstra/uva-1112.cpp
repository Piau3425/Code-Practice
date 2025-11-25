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
    int N;
    for (cin >> N; N--;) {
        int n, e, t, m, a, b, w;
        cin >> n >> e >> t >> m;
        vector<vector<PII>> g(n+1);
        while (m--) {
            cin >> a >> b >> w;
            g[b].pb({a, w});
        }

        priority_queue<PII, vector<PII>, greater<PII>> pq;
        vector<int> dis(n+1, INF), vis(n+1);
        dis[e] = 0; pq.push({0, e});

        while (pq.size()) {
            auto [d, now] = pq.top(); pq.pop();
            if (d > dis[now]) continue;

            for (auto &[toID, toDis] : g[now]) {
                if (dis[now] + toDis < dis[toID]) {
                    dis[toID] = dis[now] + toDis;
                    pq.push({dis[toID], toID});
                }
            }
        }

        int ans = 0;
        for (auto i : dis) ans += i <= t;
        cout << ans << (N ? "\n\n" : "\n");
   }
}