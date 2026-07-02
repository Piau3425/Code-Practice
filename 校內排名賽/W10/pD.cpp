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

int p, q, r, s, t, u, x;

double f(double x) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

signed main() { WA();
    for (string str; getline(cin, str);) {
        stringstream ss(str);
        ss >> p, ss >> q, ss >> r, ss >> s, ss >> t, ss >> u;
        if (f(0) < 0 || f(1) > 0) {
            cout << "No solution\n";
            continue;
        }
        double l = 0, r = 1, m;
        while (r-l > 1e-9) {
            m = l + (r-l)/2;
            if (f(m) > 0) l = m;
            else r = m;
        }
        cout << fixed << setprecision(4) << l << '\n';
    }
}