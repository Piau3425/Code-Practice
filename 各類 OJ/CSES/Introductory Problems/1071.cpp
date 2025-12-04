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
    int t;
    for (cin >> t; t--;) {
        int y, x, k = 1; cin >> y >> x;
        if (x > y) k = -1, swap(x, y);
        if (y&1) cout << 1+y*(y-1) - (y-x)*k << '\n';
        else cout << 1+y*(y-1) + (y-x)*k << '\n';
    }
}