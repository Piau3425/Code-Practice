#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PDD pair<double, double>

signed main() { WA();
    for (int n, l, w; cin >> n >> l >> w;) {
        vector<PDD> v;
        while (n--) {
            double p, r, ofs; cin >> p >> r;
            ofs = sqrt(r*r-w/2.0*w/2.0);
            if (ofs > 0) v.emplace_back(p-ofs, p+ofs);
        }
        sort(all(v));
        double now = 0;
        int cnt = 0, i = 0;
        while (now < l) {
            double mx = -1;
            while (i < v.size() && v[i].fi <= now) {
                mx = max(mx, v[i].se);
                i++;
            }
            if (mx > now) cnt++, now = mx;
            else {
                cnt = -1;
                break;
            }
        }
        cout << cnt << '\n';
    }
}