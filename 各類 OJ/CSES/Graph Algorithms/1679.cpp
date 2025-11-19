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
    vector<int> w(n+1);
    vector<vector<int>> g(n+1);
    while (m--) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        w[b]++;
    }
    queue<int> q;
    vector<int> ans;
    for (int i = 1; i <= n; i++) if (!w[i]) q.push(i);
    while (q.size()) {
        ans.pb(q.front());
        for (auto u : g[q.front()]) if (!(--w[u])) q.push(u);
        //for (auto &i : w) cout << i << ' ';
        //cout << '\n';
        q.pop();
    }
    if (ans.size() == n) for (auto &i : ans) cout << i << ' ';
    else cout << "IMPOSSIBLE\n";
}
