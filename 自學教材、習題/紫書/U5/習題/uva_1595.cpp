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
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n;
        vector<int> y(n);
        map<int, PII> x;
        for (auto &i : y) cin >> k >> i, x[i].fi += k, x[i].se++;
        double m = x[y[0]].fi/x[y[0]].se; int ck = 1;
        for (auto &i : x) if (i.se.fi/i.se.se != m) ck = 0;
        ck && cout << "YES\n" || cout << "NO\n";
    }
}