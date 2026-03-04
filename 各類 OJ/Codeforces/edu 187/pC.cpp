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

void solve() {
    int s, m; cin >> s >> m;

    if (s % (m & -m)) return void(cout << "-1\n");
    
    int l = 1, r = s, ans = s;
    while (l <= r) {
        int mid = (l+r) >> 1, rem = s;

        for (int i = 60; ~i; i--) if ((m>>i) & 1) rem -= min(mid, rem>>i) << i;
        if (!rem) ans = mid, r = mid-1; else l = mid+1;
    }
    cout << ans << '\n';
}

signed main() { WA();
    int t; for (cin >> t; t--;) solve();
}