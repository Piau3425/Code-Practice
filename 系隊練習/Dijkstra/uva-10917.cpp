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
    for (int n, m; cin >> n >> m, n;) {
        vector<vector<PII>> g(n+1);
        while (m--) {
            int a, b, w; cin >> a >> b >> w;
            g[a].pb({b, w});
            g[b].pb({a, w});
        }
        vector<int> dis(n+1, INF);
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        dis[2] = 0; pq.push({0, 2});
        while (pq.size()) {
            auto [d, now] = pq.top(); pq.pop();
            if (d > dis[now]) continue;
            for (auto [toID, toDis] : g[now]) {
                if (dis[toID] > dis[now] + toDis) {
                    dis[toID] = dis[now] + toDis;
                    pq.push({dis[toID], toID});
                }
            }
        }
        vector<vector<int>> dg(n+1);
        vector<int> w(n+1);
        for (int i = 1; i <= n; i++) for (auto [j, _] : g[i]) {
            if (dis[i] < dis[j]) dg[i].pb(j), w[j]++;
        }
        queue<int> q;
        vector<int> dp(n+1);
        dp[2] = 1; q.push(2);
        while (q.size()) {
            int now = q.front(); q.pop();
            for (auto &u : dg[now]) {
                dp[u] += dp[now];
                if (!(--w[u])) q.push(u);
            }
        }
        cout << dp[1] << '\n';
    }
}