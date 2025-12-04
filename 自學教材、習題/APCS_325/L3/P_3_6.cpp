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
    int n, l; cin >> n >> l;
    vector<int> c(n+2), h(n+2); c[0] = 0, c[n+1] = l, h[0] = INF, h[n+1] = INF;
    stack<int> sk; sk.push(0);
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> h[i];
    int cnt = 0, mx = -1e9;
    for (int i = 1; i <= n; i++) {
        if (c[i]-h[i] >= c[sk.top()] || c[i]+h[i] <= c[i+1]) {
            cnt++, mx = max(mx, h[i]);
            while (c[sk.top()]+h[sk.top()] <= c[i+1]) cnt++, mx = max(mx, h[sk.top()]), sk.pop();
        }
        else sk.push(i);
    }
    cout << cnt << '\n' << mx;
}