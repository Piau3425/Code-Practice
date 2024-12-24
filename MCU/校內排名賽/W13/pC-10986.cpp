#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long

signed main() { WA();
    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        int n, m, s, t, a, b, w;
        cin >> n >> m >> s >> t;
        vector<vector<pair<int, int>>> g(n);
        while (m--) cin >> a >> b >> w, g[a].push_back({b, w}), g[b].push_back({a, w});

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> dis(n, INF);
        q.push({0, s});
        dis[s] = 0;
        while (!q.empty()) {
            auto [d, now] = q.top(); q.pop();
            if (d > dis[now]) continue;

            for (auto &[to_idx, to_dis] : g[now]) {
                if (dis[now] + to_dis < dis[to_idx]) {
                    dis[to_idx] = dis[now] + to_dis;
                    q.push({dis[to_idx], to_idx});
                }
            }
        }

        if (dis[t] == INF) cout << "Case #" << c << ": " << "unreachable\n";
        else cout << "Case #" << c << ": " << dis[t] << '\n';
    }
}