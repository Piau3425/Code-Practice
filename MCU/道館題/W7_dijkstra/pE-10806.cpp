#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, m;
    while (cin >> n >> m, n) {
        vector<vector<pair<int , int>>> g(n+1);
        while (m--) {
            int a, b, w;
            cin >> a >> b >> w;
            g[a].push_back({b, w});
            g[b].push_back({a, w});
        }

        vector<int> dis(n+1, 0x3fffffff), vis(n+1), frd(n+1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        dis[1] = 0;

        while (pq.size()) {
            int node = pq.top().second;
            pq.pop();
            if (vis[node]) continue;
            vis[node] = 1;

            for (auto u : g[node]) {
                if (dis[node]+u.second < dis[u.first]) {
                    dis[u.first] = dis[node] + u.second;
                    pq.push({dis[u.first], u.first});
                    frd[u.first] = node;
                }
            }
        }
    }
}