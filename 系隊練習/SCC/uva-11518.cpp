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

vector<vector<int>> v;
vector<int> vis;
int cnt;

void dfs(int x) {
    cnt++;
    vis[x] = 1;
    for (auto &u : v[x]) if (!vis[u]) {
        dfs(u);
    }
}

signed main() { WA();
    int t; cin >> t;
    while (t--) {
        int n, m, l; cin >> n >> m >> l;
        v.assign(n+1, vector<int>());
        vis.assign(n+1, 0);
        while (m--) {
            int a, b; cin >> a >> b;
            v[a].pb(b);
        }
        int sum = 0;
        while (l--) {
            int x; cin >> x;
            cnt = 0;
            if (!vis[x]) dfs(x);
            sum += cnt;
        }
        cout << sum << '\n';
    }
}