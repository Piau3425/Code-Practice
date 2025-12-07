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
    int n, x; cin >> n >> x;
    vector<PII> v(n);
    for (auto &i : v) cin >> i.fi, i.se = &i-v.data()+1;
    sort(all(v));
    int a, b, c; a = -1;
    for (int i = 0; i < n; i++) {
        for (int l = i+1, r = n-1; l < r;) {
            int sum = v[l].fi + v[r].fi + v[i].fi;
            if (sum < x) l++;
            else if (sum > x) r--;
            else {
                a = v[i].se, b = v[l].se, c = v[r].se;
                break;
            }
        }
    }
    if (~a) cout << a << ' ' << b << ' ' << c;
    else cout << "IMPOSSIBLE";
}