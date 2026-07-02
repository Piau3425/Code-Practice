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
    int n, n1, d1, n2, d2;
    cin >> n >> n1 >> d1 >> n2 >> d2;
    int ans1 = -1, ans2 = -1, mn = INF;
    for (int i = 0; i*n1 <= n; i++) {
        int rem = n - i*n1;
        if (rem % n2 == 0) {
            int j = rem / n2;
            if (i*d1 + j*d2 < mn) mn = i*d1 + j*d2, ans1 = i, ans2 = j;
        }
    }
    if (~ans1) cout << ans1 << ' ' << ans2 << '\n'; else cout << "false\n";
}