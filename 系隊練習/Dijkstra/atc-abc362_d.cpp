#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n, m;
    cin >> n >> m;
    vector<int> v(n), dis(n, INF);
    vector<vector<PII>> g(n);

    for (auto &i : v) cin >> i;
    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        g[a].pb({b, w+v[b]});
        g[b].pb({a, w+v[a]});
    }

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    dis[0] = v[0];
    pq.push({v[0], 0});
    while (!pq.empty()) {
        auto [d, node] = pq.top(); pq.pop();
        if (d > dis[node]) continue;

        for (auto &[to_idx, to_dis] : g[node]) {
            if (dis[node] + to_dis < dis[to_idx]) {
                dis[to_idx] = dis[node] + to_dis;
                pq.push({dis[to_idx], to_idx});
            }
        }
    }

    for (int i = 1; i < n; i++) cout << dis[i] << ' ';
}