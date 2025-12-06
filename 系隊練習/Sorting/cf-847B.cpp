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
    vector<vector<int>> v;
    int n; for (cin >> n; n--;) {
        int x; cin >> x;
        auto it = lower_bound(all(v), x, [](vector<int> &v, int k){
            return v.back() > k;
        });
        if (it == v.end()) v.pb({x});
        else it->pb(x);
    }
    for (auto &i : v) for (auto &j : i) cout << j << " \n"[&j == &i.back()];
}