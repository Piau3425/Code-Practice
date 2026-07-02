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
    int t; for (cin >> t; t--;) {
        int l = 0, r, a, b; cin >> r;
        vector<PII> v, ans;
        while (cin >> a >> b, a || b) v.emplace_back(a, b);
        sort(all(v));
        for (int i = 0; i < v.size() && l < r; i++) {
            PII k = {-1, -1};
            for (; i < v.size() && v[i].fi <= l; i++) if (v[i].se > k.se) k = v[i]; i--;
            if (k.se > l) ans.pb(k), l = k.se;
            else {
                ans.clear();
                break;
            }
        }
        if (ans.size() && ans.back().se >= r) {
            cout << ans.size() << '\n';
            for (auto &[a, b] : ans) cout << a << ' ' << b << '\n';
        }
        else cout << "0\n";
        if (t) cout << '\n';
    }
}