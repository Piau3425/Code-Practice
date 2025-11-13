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
    for (int n; cin >> n, n;) {
        int cnt = 0, last = 1;
        while (n) {
            cnt += n&last;
            last &= n;
            n >>= 1;
        }
        cout << cnt << '\n';
    }
}