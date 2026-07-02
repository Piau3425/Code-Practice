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
    for (double x1, x2, x3, x4, y1, y2, y3, y4; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;) {
        cout << fixed << setprecision(3);
        if (x1 == x3 && y1 == y3) cout << x2 + x4 - x1 << ' ' << y2 + y4 - y1 << '\n';
        else if (x1 == x4 && y1 == y4) cout << x2 + x3 - x1 << ' ' << y2 + y3 - y1 << '\n';
        else if (x2 == x3 && y2 == y3) cout << x1 + x4 - x2 << ' ' << y1 + y4 - y2 << '\n';
        else cout << x1 + x3 - x2 << ' ' << y1 + y3 - y2 << '\n';
    }
}