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
    int n; cin >> n;
    vector<int> h(n+1), p(n+1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) cin >> p[i];
    vector<int> sk;
    int ans = 0; h[0] = INF; sk.pb(0);
    for (int i = 1; i <= n; i++) {
        /*
        int l = 0, r = sk.size()-1, idx;
        while (l <= r) {
            int mid = l+((r-l)>>1);
            if (h[sk[mid]] > h[i]+p[i]) idx = sk[mid], l = mid+1;
            else r = mid-1;
        }
        */
        ans += i-*prev(lower_bound(all(sk), h[i]+p[i], [&](int idx, int val){
            return h[idx] > val;
        }))-1;
        while (sk.size() && h[sk.back()] <= h[i]) sk.pop_back();
        sk.pb(i);
    }
    cout << ans;
}