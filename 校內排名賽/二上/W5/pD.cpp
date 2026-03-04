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
    int n;
    for (cin >> n; n--;) {
        int a, b, ans, anscnt; cin >> a >> b; ans = anscnt = 0;
        for (int i = a; i <= b; i++) {
            int cnt = 0;
            for (int j = 1; j*j <= i; j++) if (!(i%j)) {
                if (i/j == j) cnt++;
                else cnt += 2;
            }
            if (cnt > anscnt) ans = i, anscnt = cnt;
        }

        cout << "Between " << a << " and " << b << ", " << ans << " has a maximum of " << anscnt << " divisors.\n";
    }
}