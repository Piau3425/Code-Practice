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
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    int l = 0, r = *min_element(all(v))*k+1, ans = -1;
    while (l < r) {
        int m = l+((r-l)>>1), amount = 0;
        for (auto &i : v) amount += m/i;
        if (amount >= k) ans = r = m;
        else l = m+1;
    }
    cout << ans << '\n';
}