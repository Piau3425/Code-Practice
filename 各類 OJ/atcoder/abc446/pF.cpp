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

signed main() { WA();
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n+1);
    while (m--) {
        int a, b; cin >> a >> b;
        v[a].pb(b);
    }
    vector<int> vis(n+1); vis[1] = 1;
    queue<int> q;
    int len = 1, pos = 0;
    //for (auto &x : v[1]) vis[x] = 1;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            q.push(i);
            while (q.size()) {
                int now = q.front(); q.pop();
                pos++;
                for (auto &x : v[now]) {
                    if (!vis[x]) {
                        len++;
                        vis[x] = 1;
                        if (x <= i) q.push(x);
                    }
                }
            }
        }
        if (pos == i) cout << len - i << '\n';
        else cout << -1 << '\n';
    }
}