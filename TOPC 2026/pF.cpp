#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>
#define TIII tuple<int, int, int>

template<typename T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() { WA();
    int n, m; cin >> n >> m;
    vector<vector<TIII>> g(n+1);
    while (m--) {
        int u, v, t, h; cin >> u >> v >> t >> h;
        g[u].pb({v, t, h});
        g[v].pb({u, t, h});
    }
    priority_queue<PII> pq;
    vector<int> ans(n+1, -1);
    ans[1] = INF; pq.push({INF, 1});
    while (pq.size()) {
        auto [nd, now] = pq.top(); pq.pop();
        if (nd < ans[now]) continue;
        for (auto [to, td, th] : g[now]) {
            int k = min(nd, th) - td;
            if (k > ans[to]) pq.push({ans[to] = k, to});
        }
    }
    for (int i = 1; i <= n; i++) if (ans[i] >= 0) cout << 1; else cout << 0;
}