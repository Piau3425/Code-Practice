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

int n, m, mx;
vector<vector<int>> g;
vector<int> vis, c, save;

bool check(int v) {
    for (auto u : g[v]) if (c[u]) return false;
    return true;
}

void dfs(int v) {
    if (v == n) {
        int cnt = 0;
        for (auto i : c) cnt += i;
        if (cnt > mx) mx = cnt, save = c;
        return;
    }
    dfs(v+1);
    if (check(v)) c[v] = true, dfs(v+1), c[v] = false;
}

signed main() { WA();
    int t;
    for (cin >> t; t; t--) {
        cin >> n >> m;
        g.assign(n, vector<int>(0)); vis.assign(n, 0); c.assign(n, 0);
        while (m--) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            g[a].pb(b);
            g[b].pb(a);
        }

        mx = -1e9;
        dfs(0);
        cout << mx << '\n';

        int tmp = 0;
        for (int i = 0; i < n; i++) if (save[i]) cout << (tmp ? " " : "") << i+1, tmp = 1;
        cout << '\n';

        save.clear();
    }
}