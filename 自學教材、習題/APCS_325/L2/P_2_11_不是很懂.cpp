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
    set<int> p; p.insert(0);
    int ps = 0, mx = -1e9, i;
    while (n--) {
        cin >> i;
        ps += i;
        auto it = p.lower_bound(ps-k);
        if (it != p.end()) mx = max(mx, ps-*it);
        p.insert(ps);
    }
    cout << mx;
}