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
    for (int n, m; cin >> n >> m, cout << n << ' ' << m << '\n', n+m;) {
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        sort(all(v), [m](int a, int b) -> bool {
            if (a%m != b%m) return a%m < b%m;
            if ((a&1) && (b&1)) return a > b;
            if (!(a&1) && !(b&1)) return a < b;
            return a&1;
        });
        for (auto &i : v) cout << i << '\n';
    }
}