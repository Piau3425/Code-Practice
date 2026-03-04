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

double f(vector<double> &v, double x) {
    double &p = v[0], &q = v[1], &r = v[2], &s = v[3], &t = v[4], &u = v[5];
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

signed main() { WA();
    for (string s; getline(cin, s);) {
        stringstream ss(s); vector<double> v;
        while (ss>>s) v.pb(stoi(s));
        if (f(v, 0) < 0 || f(v, 1) > 0) {
            cout << "No solution\n";
            continue;
        }
        double l = 0, r = 1, ans = -1;
        while (r-l > 1e-9) {
            double x = (l+(r-l)/2);
            if (f(v, x) > 0) l = x;
            else r = x;
        }
        cout << fixed << setprecision(4) << l << '\n';
    }
}