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
#define eps 1e-3
#define PDD pair<double, double>

inline double len(PDD a, PDD b) {
    return hypot(a.fi-b.fi, a.se-b.se);
}

inline double area(PDD a, PDD b, PDD c) {
    double a1 = len(a, b), a2 = len(b, c), a3 = len(a, c), k = (a1+a2+a3) / 2;
    return sqrt(k*(k-a1)*(k-a2)*(k-a3));
}

signed main() { WA();
    char c;
    vector<vector<double>> v;
    while (cin >> c, c != '*') {
        v.pb(vector<double>());
        int i = v.size()-1;
        double k;
        if (c == 'r') {
            for (int x = 4; x--;) {
                cin >> k;
                v[i].pb(k);
            }
        }
        else if (c == 'c') {
            for (int x = 3; x--;) {
                cin >> k;
                v[i].pb(k);
            }
        }
        else {
            for (int x = 6; x--;) {
                cin >> k;
                v[i].pb(k);
            }
        }
    }
    int T = 1;
    double x, y;
    while (cin >> x >> y, x != 9999.9 || y != 9999.9) { vector<int> ans;
        for (auto &i : v) {
            if (i.size() == 3) {
                if (len({x, y}, {i[0], i[1]}) < i[2]) ans.pb(&i-&v.front());
            }
            else if (i.size() == 4) {
                if (x > i[0] && x < i[2] && y < i[1] && y > i[3]) ans.pb(&i-&v.front());
            }
            else {
                double
                a = area({i[0], i[1]}, {i[2], i[3]}, {x, y}),
                b = area({i[2], i[3]}, {i[4], i[5]}, {x, y}),
                c = area({i[4], i[5]}, {i[0], i[1]}, {x, y});
                if (a >= eps && b >= eps && c >= eps && fabs(a+b+c-area({i[0], i[1]}, {i[2], i[3]}, {i[4], i[5]})) <= eps) ans.pb(&i-&v.front());
            }
        }
            
        if (ans.size()) for (auto &i : ans) cout << "Point " << T << " is contained in figure " << i+1 << '\n';
        else cout << "Point " << T << " is not contained in any figure\n";
        T++;
    }
}