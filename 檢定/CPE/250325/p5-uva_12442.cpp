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

vector<int> g, vis, cnt;

int dfs(int v) {
    vis[v] = 1;
    cnt[v] = 1;
    if (!vis[g[v]]) cnt[v] = dfs(g[v]) + 1;
    vis[v] = 0;
    return cnt[v];
}

signed main() { WA();
    int t, T = 1;
    for (cin >> t; T <= t; T++) { cout << "Case " << T << ": ";
        int n; cin >> n;
        g.assign(n+1, 0);
        cnt.assign(n+1, 0);
        vis.assign(n+1, 0);
        for (int i = 0; i < n; i++) {
            int a, b; cin >> a >> b;
            g[a] = b;
        }

        int ans;
        for (int i = 1, mx = -1e9; i <= n; i++) {
            if (!cnt[i]) dfs(i);
            if (cnt[i] > mx) mx = cnt[i], ans = i;
        }

        cout << ans << '\n';
    }
}