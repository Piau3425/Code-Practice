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
double mn;

void f(int l, int r) {
    if (l+1 == r) return;

    int m = (l+r)/2;
    double midx = v[m].fi;
    f(l, m);
    f(m, r);

    inplace_merge(v.begin()+l, v.begin()+m, v.begin()+r, [](PDD a, PDD b){
        return a.se < b.se;
    });
    vector<PDD> t;
    for (int i = l; i < r; i++) if (abs(v[i].fi-midx) < mn) t.pb({v[i].fi, v[i].se});
    for (int i = 0; i < t.size(); i++) {
        for (int j = i+1; j < t.size(); j++) {
            if (t[j].se-t[i].se < mn) {
                mn = min(mn, hypot(t[i].fi-t[j].fi, t[i].se-t[j].se));
            }
            else break;
        }
    }
}

signed main() { WA();
    for (int n; cin >> n, n;) {
        v.assign(n, {});
        for (auto &i : v) cin >> i.fi >> i.se;
        sort(all(v)); mn = INF;
        f(0, n);
        if (mn < 10000) cout << fixed << setprecision(4) << mn << '\n';
        else cout << "INFINITY\n";
    }
}