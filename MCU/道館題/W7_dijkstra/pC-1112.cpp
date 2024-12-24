#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int N, I;
    for (cin >> N; N--;) {
        int n, e, t, m;
        cin >> n >> e >> t >> m;
        vector<vector<pair<int, int>>> g(n+1);
        while (m--) {
            int a, b, w;
            cin >> a >> b >> w;
            g[b].push_back({a, w});
        }

        vector<int> dis(n+1, 0x3fffffff), vis(n+1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, e});
        dis[e] = 0;

        while (pq.size()) {
            int now = pq.top().second; pq.pop();

            if (vis[now]) continue;
            vis[now] = 1;

            for (auto &[to_idx, to_dis] : g[now]) {
                if (dis[now] + to_dis < dis[to_idx]) {
                    dis[to_idx] = dis[now] + to_dis;
                    pq.push({dis[to_idx], to_idx});
                }
            }
        }

        int ans = 0;
        for (auto i : dis) if (i <= t) ans++;
        cout << ans << '\n';
        if (N) cout << '\n';
   }
}