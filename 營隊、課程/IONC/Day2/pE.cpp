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
#define TIII tuple<int, int, int>

signed main() {
    int n, m;
    while (cin >> n >> m) {
        vector<int> dis(n+1, INF), vis(n+1);
        vector<vector<PII>> g(n+1);

        while (m--) {
            int a, b, w;
            cin >> a >> b >> w;
            g[a].pb({b, w});
            g[b].pb({a, w});
        }

        priority_queue<TIII, vector<TIII>, greater<TIII>> pq;
        dis[1] = 0;
        int cnt = 0;
        pq.push({0, 1, -999});
        //for (auto &i : g[1]) pq.push({1, i.fi, i.se});
        while (pq.size()) {
            auto [d, node, color] = pq.top(); pq.pop();
            if (d > n/2) continue;
            for (auto &[to_idx, to_color] : g[node]) {
                if (color != to_color) {
                    pq.push({d+1, to_idx, to_color});
                    if (d+1 < dis[to_idx]) dis[to_idx] = d+1, cnt++;
                    if (cnt == n) break;
                }
            }
        }
        for (int i = 1; i <= n; i++) cout << (dis[i] == INF ? -1 : dis[i]) << ' ';
        cout << '\n';
    }
}