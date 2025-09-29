#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int N;
    for (cin >> N; N--;) {
        int n, e, t, m, a, b, w;
        cin >> n >> e >> t >> m;
        vector<vector<pair<int, int>>> g(n+1);
        while (m--) {
            cin >> a >> b >> w;
            g[b].pb({a, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(n+1, INF), vis(n+1);
        dis[e] = 0; pq.push({0, e});

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
        for (auto i : dis) ans += i <= t;
        cout << ans << (N ? "\n\n" : "\n");
   }
}