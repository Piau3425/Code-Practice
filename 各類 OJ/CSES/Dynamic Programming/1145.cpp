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
    int n; cin >> n;
    vector<int> v(n), dp;
    for (auto &i : v) cin >> i;
    for (auto &i : v) {
        if (dp.empty() || i > dp.back()) dp.pb(i);
        else *lower_bound(all(dp), i) = i;
    }
    cout << dp.size() << '\n';
}