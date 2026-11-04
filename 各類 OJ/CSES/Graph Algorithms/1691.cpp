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
#define SZ(x) ((int)(x).size())

template<typename T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, m;

vector<vector<PII>> g;
vector<bool> used;
vector<int> ptr, path;
void euler(int u) {
    while (ptr[u] < SZ(g[u])) {
        auto [to, id] = g[u][ptr[u]++];
        if (used[id]) continue;
        used[id] = 1;
        euler(to);
    }
    path.pb(u);
}

signed main() { WA();
    cin >> n >> m;
    g.assign(n, {});
    used.assign(m, false);
    ptr.assign(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].pb({b, i});
        g[b].pb({a, i});
    }
    euler(0);
    reverse(all(path));
    int flag = 1;
    for (auto &i : g) if (i.size()&1) flag = 0;
    if (path.size() != m+1) flag = 0;
    if (flag) for (auto &i : path) cout << i+1 << ' ';
    else cout << "IMPOSSIBLE";
}