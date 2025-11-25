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
    int a, b, c, d; cin >> a >> b >> c >> d;
    int ans = 0, now = 1;
    for (int i = 1; i <= b; now++) {
        if (now%a) ans += c, i++;
        else ans += d;
    }
    if (!(now%a)) ans += d; 
    cout << ans;
}