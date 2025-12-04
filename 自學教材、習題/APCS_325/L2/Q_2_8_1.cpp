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

void ext_euc(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1;
        y = 0;
        return;
    }
    ext_euc(b, a%b, y, x);
    y -= a/b*x;
}

signed main() { WA();
    int n, p; cin >> n >> p;
    while (n--) {
        int t; cin >> t;
        int x, y;
        ext_euc(t, p, x, y);
        cout << (x+p)%p << ' ';
    }
}