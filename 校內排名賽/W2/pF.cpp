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

vector<int> lis(vector<int> v) {
    vector<int> ret(v.size()), dp;
    for (int i = 0; i < v.size(); i++) {
        auto it = lower_bound(all(dp), v[i]);
        if (it == dp.end()) dp.pb(v[i]), ret[i] = dp.size();
        else *it = v[i], ret[i] = it-dp.begin()+1;
    }
    return ret;
}

signed main() { WA();
    for (int n; cin >> n;) {
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        vector<int> l = lis(v), r = lis(vector<int>(v.rbegin(), v.rend()));
        reverse(all(r));

        int ans = 0;
        for (int i = 0; i < n; i++) ans = max(ans, 2*min(l[i], r[i])-1);
        cout << ans << '\n';
    }
}