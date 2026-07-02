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
    int t; for (cin >> t; t--;) {
        int n, mn = 1e9; cin >> n;
        for (int a = 1; a <= n; a++) for (int b = a; a*b*b <= n; b++) if (!(n%(a*b))) {
            int c = n/a/b;
            mn = min(mn, 2*(a*b + b*c + c*a));
        }
        cout << mn << '\n';
    }
}