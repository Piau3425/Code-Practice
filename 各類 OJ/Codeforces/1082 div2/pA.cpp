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
    int t, x, y;
    for (cin >> t; t--;) {
        cin >> x >> y;
        if ((x-2*y)%3 == 0 && (y >= 0 ? x >= 2*y : x >= -4*y)) cout << "YES\n"; else cout << "NO\n";
    }
}