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
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        sort(all(v));
        int ans = 0;
        deque<int> dq;
        for (int i = 0; i < n/2; i++) {
            if (dq.size()) {
                if (abs(dq.front()-v[i]) > abs(dq.back()-v[i])) dq.push_front(v[i]);
                else dq.push_back(v[i]);
                if (abs(dq.front()-v[n-i-1]) > abs(dq.back()-v[n-i-1])) dq.push_front(v[n-i-1]);
                else dq.push_back(v[n-i-1]);
            }
            else {
                dq.pb(v[i]);
                if (abs(dq.front()-v[n-i-1]) > abs(dq.back()-v[n-i-1])) dq.push_front(v[n-i-1]);
                else dq.push_back(v[n-i-1]);
            }
        }
        if (n&1) {
            if (abs(dq.front()-v[n/2]) > abs(dq.back()-v[n/2])) dq.push_front(v[n/2]);
            else dq.pb(v[n/2]);
        }
        for (int i = 1; i < n; i++) ans += abs(dq[i]-dq[i-1]);
        cout << ans << '\n';
    }
}