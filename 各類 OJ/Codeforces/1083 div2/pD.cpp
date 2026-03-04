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
    int t; for (cin >> t; t--;) {
        int n; cin >> n;
        vector<int> a(n), l(n, -1), r(n, -1), stk;
        for (auto &i : a) cin >> i;
        
        for (int i = 0; i < n; i++) {
            int lst = -1;
            while (stk.size() && a[stk.back()] < a[i]) lst = stk.back(), stk.pop_back();
            if (~lst) l[i] = lst;
            if (stk.size()) r[stk.back()] = i;
            stk.pb(i);
        }
        
        vector<int> q = {stk[0]}, d(n, 0); d[stk[0]] = 1;
        int mx = 1;

        for (int i = 0; i < q.size(); i++) {
            int u = q[i]; mx = max(mx, d[u]);
            if (~l[u]) d[l[u]] = d[u] + 1, q.pb(l[u]);
            if (~r[u]) d[r[u]] = d[u] + 1, q.pb(r[u]);
        }
        
        cout << n - mx << "\n";
    }
}