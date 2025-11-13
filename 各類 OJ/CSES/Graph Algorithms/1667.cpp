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

int n, m;

signed main() { WA();
    cin >> n >> m;
    vector<vector<int>> v(n+1);
    vector<int> vis(n+1);
    while (m--) {
        int a, b; cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    vector<int> path(n+1);
    queue<int> q; q.push(1);
    while (q.size()) {
        //cout << q.front();
        int now = q.front(); q.pop();
        if (now == n) break;
        for (auto u : v[now]) if (!vis[u]) {
            vis[u] = 1;
            path[u] = now;
            q.push(u);
        }
    }
    if (path[n]) {
        vector<int> ans;
        while (n != 1) {
            ans.pb(n);
            n = path[n];
        } ans.pb(1);
        cout << ans.size() << '\n';
        for (int i = ans.size()-1; i >= 0; i--) cout << ans[i] << ' ';
        cout << '\n';
    }
    else cout << "IMPOSSIBLE\n";
}