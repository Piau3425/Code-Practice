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
    vector<vector<PII>> g(n+1);
    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].pb({b, w});
    }
    int hasCycle = 0, ed;
    for (int i = 1; i <= n && !hasCycle; i++) {
        vector<int> dis(n+1, INF), vis(n+1), cnt(n+1), path(n+1);
        queue<int> q;
        q.push(i); dis[i] = 0; vis[i] = 1; path[i] = -1;
        while (q.size() && !hasCycle) {
            int nowID = q.front(); q.pop();
            vis[nowID] = 0;
            for (auto [toID, toDist] : g[nowID]) {
                if (dis[toID] > dis[nowID] + toDist) {
                    if (++cnt[toID] >= n) {
                        hasCycle = 1;
                        ed = toID;
                        path[toID] = nowID;
                        break;
                    }
                    dis[toID] = dis[nowID] + toDist;
                    if (!vis[toID]) q.push(toID), vis[toID] = 1;
                    path[toID] = nowID;
                }
            }
        }
        if (hasCycle) {
            cout << "YES\n";
            stack<int> st;
            vector<int> inst(n+1);
            while (!inst[ed]) {
                inst[ed] = 1;
                st.push(ed);
                ed = path[ed];
            }
            cout << ed; while (st.top() != ed) {
                cout << ' ' << st.top();
                st.pop();
            } cout << ' ' << ed;
        }
    }
    if (!hasCycle) cout << "NO\n";
}