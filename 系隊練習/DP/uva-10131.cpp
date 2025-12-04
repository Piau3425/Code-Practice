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
#define TIII tuple<int, int, int>

signed main() { WA();
    vector<TIII> v; int id = 0;
    for (int a, b; cin >> a >> b;) v.pb({a, b, id++});
    int n = v.size();
    sort(all(v), [](TIII a, TIII b) {
        auto [a1, a2, a3] = a; auto [b1, b2, b3] = b;
        if (a1 == b1) return a2 > b2;
        return a1 < b1;
    });
    vector<int> dp(n, 1), path(n);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            auto [a1, a2, a3] = v[i]; auto [b1, b2, b3] = v[j];
            if (a1 < b1 && a2 > b2 && dp[j] < dp[i]+1) dp[j] = dp[i]+1, path[j] = i;
        }
    }
    cout << *max_element(all(dp)) << '\n';
    int now = max_element(all(dp))-dp.begin();
    vector<int> ans;
    while (now) {
        ans.pb(get<2>(v[now]));
        now = path[now];
    }
    for (auto &i : vector<int>(ans.rbegin(), ans.rend())) cout << i+1 << '\n';
}