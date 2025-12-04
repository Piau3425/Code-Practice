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
    sort(all(v));
    deque<int> dq; int mx = -INF;
    for (int ldx = 0, rdx = 0; rdx < n; rdx++) {
        dq.pb(v[rdx]);
        while (dq.back()-dq.front() > k) ldx++, dq.pop_front();
        mx = max(mx, (int)dq.size());
    }
    cout << mx << '\n';
}