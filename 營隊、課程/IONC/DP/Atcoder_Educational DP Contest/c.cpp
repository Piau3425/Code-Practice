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
    int n; cin >> n;
    vector<tuple<PII, PII, PII>> v(n);
    for (auto &[a, b, c] : v) cin >> a.fi >> b.fi >> c.fi, a.se = a.fi, b.se = b.fi, c.se = c.fi;
    for (int i = 1; i < n; i++) {
        auto &[a, b, c] = v[i];
    }
}