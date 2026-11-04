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
#define TIII tuple<int, int, int>

signed main() { WA();
    int n; cin >> n;
    vector<PII> v(n);
    for (auto &i : v) cin >> i.fi >> i.se;
    sort(all(v));
    int now = 0, ans = 1;
    for (int i = 0; i+1 < n; i++) {
        auto [a, b] = v[i];
        auto [c, d] = v[i+1];
        if (c <= b) now++;
        else ans = max(now+1, ans), now = 0;
    }
    ans = max(now+1, ans);
    cout << ans << '\n';
    
}