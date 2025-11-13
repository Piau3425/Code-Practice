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
    int f, r; while (cin >> f >> r, f) {
        vector<double> fv(f), rv(r), d;
        for (auto &i : fv) cin >> i;
        for (auto &i : rv) cin >> i;
        for (auto &i : rv) for (auto &j : fv) {
            d.pb(i/j);
            //cout << i/j << ' ';
        }
        sort(all(d));
        double mx = -1e9;
        for (int i = 1; i < d.size(); i++) {
            mx = max(d[i]/d[i-1], mx);
            //cout << fixed << setprecision(2) << d[i]/d[i-1] << ' ';
        }
        cout << fixed << setprecision(2) << mx << '\n';
    }
}