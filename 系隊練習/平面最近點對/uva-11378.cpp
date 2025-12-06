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

vector<PDD> v;
double mx;

void f(int l, int r) {
    if (l+1 == r) return;
    int m = (l+r)/2;
    double midx = v[m].fi;
    f(l, m); f(m, r);
    inplace_merge(v.begin()+l, v.begin()+m, v.begin()+r, [](PDD a, PDD b){
        return a.se < b.se;
    });
    vector<PDD> t;
    for (int i = l; i < r; i++) if (abs(v[i].fi-midx) < mx) t.pb({v[i].fi, v[i].se});
    for (int i = 0; i < t.size(); i++) {
        for (int j = i+1; j < t.size(); j++) {
            if (t[j].se-t[i].se < mx) mx = min(mx, max(t[j].se-t[i].se, abs(t[j].fi-t[i].fi)));
            else break;
        }
    }
}

signed main() { WA();
    for (int n; cin >> n;) {
        v.assign(n, {});
        for (auto &i : v) cin >> i.fi >> i.se;
        sort(all(v));
        mx = INF;
        f(0, n);
        cout << mx << '\n';
    }
}