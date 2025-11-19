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

int mx = -1e9, sum, n;
vector<deque<pair<char, int>>> v;
vector<vector<int>> dp;

void dfs(int x) {
    for (int i = 0; i < n; i++) {
        if (i == x || v[i].empty() || v[x].empty()) continue;
        if (v[x][0].fi == v[i][0].fi) {
            if (~dp[][]) {
                return sum += dp[x][i], mx = max(mx, sum), sum -= dp[x][i], void();
            }
            else {
                auto a = v[x][0], b = v[i][0];
                sum += v[x][0].se + v[i][0].se;
                v[x].pop_front(); v[i].pop_front();
                dfs(x); dfs(i);
                v[x].push_front(a); v[i].push_front(b);
                sum -= v[x][0].se + v[i][0].se;
            }
        }
    }
    return mx = max(mx, sum), void();
}

signed main() { WA();
    cin >> n;
    v.resize(n);
    for (auto &i : v) {
        int k;
        for (cin >> k; k--;) {
            char ch; int p;
            cin >> ch >> p;
            i.pb({ch, p});
        }
    }
    dp.resize(n); for (int i = 0; i < n; i++) dp[i].assign(v[i].size(), -1);
    for (int i = 0; i < n; i++) {
        sum = 0;
        dfs(i);
    }
    cout << mx;
}