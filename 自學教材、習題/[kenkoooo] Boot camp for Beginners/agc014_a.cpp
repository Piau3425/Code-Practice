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
    int a, b, c; cin >> a >> b >> c;
    int cnt = 0;
    if (a == b && b == c && !(a&1)) return cout << -1, 0;
    while (!(a&1 || b&1 || c&1)) {
        int aa = b/2 + c/2, bb = a/2 + c/2, cc = a/2 + b/2;
        a = aa, b = bb, c = cc;
        cnt++;
        //cout << a << ' ' << b << ' ' << c << '\n';
    }
    cout << cnt;
}