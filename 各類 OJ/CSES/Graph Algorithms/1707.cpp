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

vector<vector<int>> v;
int n, m;

int bfs(int x) {
    vector<int> vis(n+1), dis(n+1);
    queue<PII> q; q.push({x, 0}); vis[x] = 1;
    int mn = INF;
    while (q.size()) {
        auto [now, last] = q.front(); q.pop();
        for (auto &to : v[now]) {
            if (vis[to]) {
                if (to != last) mn = min(mn, dis[now] + dis[to] + 1);
            }
            else {
                dis[to] = dis[now] + 1;
                vis[to] = 1;
                q.push({to, now});
            }
        }
    }
    return mn;
}

signed main() { WA();
    cin >> n >> m;
    v.resize(n+1);
    while (m--) {
        int a, b; cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, bfs(i));
        if (ans == 3) break;
    }
    if (ans == INF) cout << "-1\n";
    else cout << ans << '\n';
}