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
    int n, m;
    while (cin >> n >> m, n+m) {
        vector<vector<PII>> g(n+1); // {連結的節點, 兩點距離}
        int x, y, k; cin >> x >> y >> k;
        while (m--) {
            int a, b, w;
            cin >> a >> b >> w;
            g[a].pb({b, w});
        }
        
        vector<int> vis(n+1);
        priority_queue<PII, vector<PII>, greater<PII>> pq; // {目前距離, 當前節點}
        pq.push({0, x});
        int ans = -1;
        while (pq.size()) {
            PII now = pq.top(); pq.pop();
            if (vis[now.se]++ > k) continue;
            if (now.se == y && vis[now.se] == k) {
                ans = now.fi;
                break;
            }
            for (auto &i : g[now.se]) pq.push({now.fi+i.se, i.fi});
        }

        cout << ans << '\n';
    }
}