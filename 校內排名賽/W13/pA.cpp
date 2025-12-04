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
    int t, T = 0;
    for (cin >> t; t--;) { cout << "Case " << ++T << ": ";
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << (x2+y2)*(x2+y2+1)/2 + x2 - (x1+y1)*(x1+y1+1)/2 - x1 << '\n';
    }
}