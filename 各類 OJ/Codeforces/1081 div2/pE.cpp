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
#define MAXN 1000005

bitset<MAXN> vis;
vector<vector<PII>> adj;
vector<int> a, b, cnt, ans;

void dfs(int u) {
    while (adj[u].size()) {
        auto [v, id] = adj[u].back(); adj[u].pop_back();
        if (vis[abs(id)]) continue;
        vis[abs(id)] = 1;
        if (id < 0) ans.pb(-id);
        dfs(v);
    }
}

void solve() {
    int n; cin >> n;
    adj.assign(n + 1, {}); 
    a.assign(n + 1, 0); b.assign(n + 1, 0); cnt.assign(n + 1, 0);
    ans.clear();
    for (int i = 1; i <= n; i++) vis[i] = 0;

    for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;
    for (int i = 1; i <= n; i++) cin >> b[i], cnt[b[i]]++;

    for (int i = 1; i <= n; i++) if (cnt[i] & 1) return void(cout << "-1\n");

    for (int i = 1; i <= n; i++) {
        adj[a[i]].pb({b[i], i});
        adj[b[i]].pb({a[i], -i});
    }

    for (int i = 1; i <= n; i++) if (adj[i].size()) dfs(i);

    cout << ans.size() << "\n";
    for (auto &i : ans) cout << i << " \n"[&i == &ans.back()];
    if (!ans.size()) cout << "\n";
}

signed main() { WA();
    int t; cin >> t;
    while (t--) solve();
}