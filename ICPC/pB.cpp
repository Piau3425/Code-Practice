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
#define busTime (double)(bus[id].se-bus[id].fi)/x+(double)(l-bus[id].se)/y

signed main() { WA();
    int n, m, l;
    double x, y; cin >> n >> m >> l >> x >> y;
    vector<tuple<int, int, double>> event; // trigger position, type, id
    vector<pair<int, int>> bus(n);
    for (int i = 0; i < n; i++) {
        int &s = bus[i].fi, &t = bus[i].se;
        cin >> s >> t;
        t = min(l, t);
        event.pb({s, 1, i});
        event.pb({t, 2, i});
    }
    for (int i = 0; i < m; i++) {
        int p; cin >> p;
        event.pb({p, 3, i});
    }
    sort(all(event));
    multiset<pair<double, int>> plan;
    vector<double> ans(m);
    int cnt = 0;
    for (auto &[pos, type, id] : event) {
        if (type == 1) plan.insert({busTime, id});
        else if (type == 2) plan.erase({busTime, id});
        else {
            if (plan.size()) ans[id] = min(plan.begin()->fi, (double)(l-pos)/y);
            else ans[id] = (double)(l-pos)/y;
            if (++cnt == m) break;
        }
    }
    for (auto &i : ans) cout << fixed << setprecision(14) << i << '\n';
}