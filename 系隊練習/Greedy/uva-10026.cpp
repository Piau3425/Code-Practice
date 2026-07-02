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
    int t; for (cin >> t; t--;) {
        int n, k = 0; cin >> n;
        vector<TIII> v(n);
        for (auto &i : v) cin >> get<0>(i) >> get<1>(i), get<2>(i) = ++k;
        sort(all(v), [](TIII a, TIII b){
            return get<1>(b)*get<0>(a) < get<0>(b)*get<1>(a);
        });
        for (auto &i : v) {
            cout << get<2>(i) << " \n"[&i == &v.back()];
        }
        if (t) cout << '\n';
    }
}