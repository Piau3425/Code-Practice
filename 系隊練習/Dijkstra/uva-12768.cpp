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

int ans, n, m;
vector<vector<PII>> g;

bool spfa() {
    vector<int> dis(n+1, -INF), vis(n+1), cnt(n+1);
    queue<int> q;
    dis[1] = 0; vis[1] = 1; q.push(1);
    while (q.size()) {
        int now = q.front(); q.pop();
        vis[now] = 0;
        for (auto [toID, toDis] : g[now]) {
            if (dis[toID] < dis[now] + toDis) {
                dis[toID] = dis[now] + toDis;
                if (++cnt[toID] >= n) return false;
                if (!vis[toID]) q.push(toID), vis[toID] = 1;
            }
        }
    }
    ans = -INF;
    for (int i = 1; i <= n; i++) ans = max(ans, dis[i]);
    return true;
}


signed main() { WA();
    for (; cin >> n >> m, n+m;) {
        g.assign(n+1, vector<PII>());
        while (m--) {
            int a, b, w; cin >> a >> b >> w;
            g[a].pb({b, w});
        }
        if (spfa()) cout << ans << '\n';
        else cout << "Unlimited!\n";
    }
}