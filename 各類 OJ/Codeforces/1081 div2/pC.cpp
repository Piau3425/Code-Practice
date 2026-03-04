#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/10
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int t; for (cin >> t; t--;) {
        int n, h, k; cin >> n >> h >> k;
        vector<int> v(n+1), pre(n+2), preMin(n+2, INF), sufMax(n+2);
        for (int i = 1; i <= n; i++) cin >> v[i], pre[i] = pre[i-1] + v[i], preMin[i] = min(preMin[i-1], v[i]);
        for (int i = n; i; i--) sufMax[i] = max(sufMax[i+1], v[i]);
        
        int ans = INF;
        for (int i = 1, total, circle; i <= n; i++) {
            total = max(pre[i], i < n ? pre[i] - preMin[i] + sufMax[i+1] : 0);
            circle = h > total ? (h - total + pre[n] - 1) / pre[n] : 0;
            ans = min(ans, circle * (n+k) + i);
        }
        cout << ans << '\n';
    }
}