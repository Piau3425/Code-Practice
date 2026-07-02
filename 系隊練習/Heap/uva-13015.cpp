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
    for (int a, b, e, p; cin >> a >> b >> e >> p;) {
        vector<vector<int>> g(e);
        vector<int> w(e);
        while (p--) {
            int u, v; cin >> u >> v;
            g[u].pb(v);
            w[v]++;
        }
        priority_queue<int> pq;
        for (int i = 0; i < e; i++) if (!w[i]) pq.push(i);
        
    }
}