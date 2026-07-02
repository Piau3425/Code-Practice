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
    int t = 1, T; for (cin >> T; t <= T; t++) { cout << "Night " << t << ": ";
        int x1, y1, x2, y2, x3, y3, x4, y4; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        int a = (x2 - x1) * (y2 - y1), b = (x4 - x3) * (y4 - y3), c = max(0LL, min(x2, x4) - max(x1, x3)) * max(0LL, min(y2, y4) - max(y1, y3));
        cout << c << ' ' << a+b-2*c << ' ' << 10000-a-b+c << '\n';
    }
}