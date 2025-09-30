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

int ans = 0;
vector<int> dp;
vector<vector<int>> v;

int dfs(int x) {
    if (~dp[x]) return dp[x];
    int &now = dp[x] = 0;
    for (auto &u : v[x]) now = max(now, dfs(u) + 1);
    return now;
}

signed main() { WA();
    int n, m; cin >> n >> m;
    dp.assign(n+1, -1);
    v.assign(n+1, vector<int>());
    while (m--) {
        int a, b; cin >> a >> b;
        v[a].pb(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!~dp[i]) dfs(i);
        ans = max(dp[i], ans);
    }
    cout << ans;
}