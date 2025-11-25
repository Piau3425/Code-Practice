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
    int n, m, l;
    double x, y; cin >> n >> m >> l >> x >> y;
    vector<tuple<int, int, int>> event(n); // trigger position, type, id
    for (auto &[s, id, t] : event) {
        cin >> s >> t;
        t = min(l, t);
        id = -1;
    }
    for (int i = 0; i < m; i++) {
        int p; cin >> p;
        event.pb({p, 1, i});
    }
    sort(all(event));
    vector<double> ans(m);
    double mn = INF;
    for (auto &[a, type, b] : event) {
        if (~type) ans[b] = min(mn, (l-a)/y);
        else mn = min(mn, (double)(b-a)/x+(double)(l-b)/y);
    }
    for (auto &i : ans) cout << fixed << setprecision(14) << i << '\n';
}