#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int N, I;
    for (cin >> N, I = 1; I <= N; I++) {
        int n, m, s, t; // node (0, n-1), edge
        cin >> n >> m >> s >> t;
        vector<vector<pair<int, int>>> g(n);
        while (m--) {
            int a, b, w;
            cin >> a >> b >> w;
            g[a].push_back({b, w});
            g[b].push_back({a, w});
        }

        vector<int> vis(n), dis(n, 0x3fffffff);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // node, weight
        pq.push({0, s});
        dis[s] = 0;

        while (pq.size()) {
            // 取最小距離點
            int node = pq.top().second;
            pq.pop();

            if (vis[node]) continue;
            vis[node] = 1;

            for (auto u : g[node]) {
                int v = u.first; // 最小距離點的鄰接節點
                int w = u.second; // 最小點到該點距離
                if (dis[node]+w < dis[v]) {
                    dis[v] = dis[node] + w;
                    pq.push({dis[v], v});
                }
            }
        }

        /*
        for (int i = 0; i < n; i++) {
            int mnod, mnval = 0x3fffffff;
            for (int j = 0; j < n; j++) {
                if (!vis[j] && dis[j] <= mnval) mnod = j, mnval = dis[j];
            }

            vis[mnod] = 1;

            for (auto u : g[mnod]) {
                int v = u.first; // mnod 連接的節點
                int d = u.second; // mnod 兩節點 edge 的權重
                dis[v] = min(dis[v], dis[mnod] + d); // 檢查是否能縮短到 v 的距離 
            }
        }
        */
        cout << "Case #" << I << ": "; 
        if (!vis[t]) cout << "unreachable\n";
        else cout << dis[t] << '\n';
        vis.clear(); dis.clear(); g.clear();    
    }
}