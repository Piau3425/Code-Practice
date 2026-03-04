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

void solve() {
    int n, m; cin >> n >> m;
    int limit = n + m, lcm = 1, A = 0, B = 0, S = 0;
    vector<int> a(limit + 1, 0), isDivBy(limit + 1, 0);

    for (int i = 0, x; i < n; i++) {
        cin >> x, a[x] = 1;
        if (lcm <= limit) lcm = lcm / __gcd(lcm, x) * x;
    }

    for (int i = 1; i <= limit; i++) if (a[i] && !isDivBy[i])
        for (int j = i; j <= limit; j += i) isDivBy[j] = 1;

    for (int i = 0, y; i < m; i++) {
        cin >> y;
        if (y % lcm == 0) A++;
        else if (div[y]) S++;
        else B++;
    }

    cout << (S & 1 ? (A >= B ? "Alice\n" : "Bob\n") : (A > B ? "Alice\n" : "Bob\n"));
}

signed main() { WA();
    int t;
    for (cin >> t; t--;) solve();
}