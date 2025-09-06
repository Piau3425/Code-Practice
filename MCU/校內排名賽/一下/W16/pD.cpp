#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n, T = 0; 
    while (cin >> n, n) {
        int s, e, t; cin >> s >> e >> t;
        vector<vector<int>> v(n+1, vector<int>(n+1));
        while (t--) {
            int a, b, w;
            cin >> a >> b >> w;
            v[a][b] += w;
            v[b][a] += w;
        }

        int ans = 0;
        while (1) {
            vector<int> vis(n+1), path(n+1); vis[s] = 1;
            queue<int> q; q.push(s);
            int ck = 0;
            while (q.size()) {
                int now = q.front(); q.pop();
                if (now == e) {
                    ck = 1;
                    break;
                }
                for (int i = 1; i <= n; i++) if (v[now][i] && !vis[i]) {
                    vis[i] = 1;
                    path[i] = now;
                    q.push(i);
                }
            }
            if (ck) {
                int now = e, mn = e;
                while (now != s) {
                    mn = min(mn, v[path[now]][now]);
                    now = path[now];
                }
                ans += mn; now = e;
                while (now != s) {
                    v[path[now]][now] -= mn;
                    v[now][path[now]] += mn;
                    now = path[now];
                }
            }
            else break;
        }
        
        cout << "Network " << ++T << "\nThe bandwidth is " << ans << ".\n\n";
    }
}