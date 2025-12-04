#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long

int cnt;
vector<int> vis;
vector<vector<int>> g;

void dfs(int v) {
    cnt++;
    for (auto u : g[v]) if (!vis[u]) {
        vis[u] = 1;
        dfs(u);
    }
}

signed main() { WA();
    int n, m, t;
    while (cin >> n, n) {
        g.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> m;
            while (m--) cin >> t, g[i].push_back(t-1);
        }

        int mx = -1e9, ans;
        for (int i = n-1; i >= 0; i--) {
            cnt = 0;
            vis.assign(n, 0);
            dfs(i);
            if (cnt >= mx) ans = i, mx = cnt;
        }
        cout << ans+1 << '\n';
        g.clear();
    }
}