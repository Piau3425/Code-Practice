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
    for (int n, d, r; cin >> n >> d >> r, n+d+r;) {
        vector<int> a(n), b(n);
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;
        sort(all(a)); sort(all(b), greater<int>());
        int ans = 0;
        for (int i = 0; i < n; i++) ans += r*(max(0LL, a[i]+b[i]-d));
        cout << ans << '\n';
    }
}