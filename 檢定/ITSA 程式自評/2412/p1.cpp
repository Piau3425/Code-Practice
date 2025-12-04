#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long

signed main() { WA();
    int n;
    cin >> n;
    vector<pair<double, double>> v(n);
    for (auto &i : v) cin >> i.fi >> i.se;

    double mn = 1e9;
    for (auto &i : v) mn = min(mn, i.fi/i.se);
    cout << fixed << setprecision(1) << mn/60 << '\n';
}