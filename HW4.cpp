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
#define PDD pair<double, double>
#define TDDD tuple<double, double, double>
#define eps 1e-9

bool getIntersection(TDDD l1, TDDD l2, PDD &p) {
    auto [a1, b1, c1] = l1;
    auto [a2, b2, c2] = l2;
    double D = a1 * b2 - b1 * a2;
    if (abs(D) < 1e-9) return false;
    p = {(c1 * b2 - b1 * c2) / D, (a1 * c2 - c1 * a2) / D};
    return true;
}

bool isValid(PDD p) {
    if (p.fi < -eps || p.se < -eps || p.fi + p.se > 4 + eps || p.fi + 3 * p.se > 6 + eps) return false;
    return true;
}

signed main() { WA();
    vector<TDDD> lines = {
        {1.0, 1.0, 4.0},
        {1.0, 3.0, 6.0},
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0}
    };

    int n = lines.size();
    double mx = -1e9; PDD ans;
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
        PDD p;
        if (getIntersection(lines[i], lines[j], p) && isValid(p) && 3*p.fi + 5*p.se > mx) {
            ans = p;
            mx = 3*p.fi + 5*p.se;
        }
    }

    cout << ans.fi << ' ' << ans.se << '\n' << mx << '\n';
}