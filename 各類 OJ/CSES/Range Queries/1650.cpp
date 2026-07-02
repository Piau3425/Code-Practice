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
    for (int n, q; cin >> n >> q;) {
        vector<int> v(n), pre(n+1); for (auto &i : v) cin >> i;
        for (int i = 1; i <= n; i++) pre[i] = pre[i-1] ^ v[i-1];
        while (q--) {
            int a, b; cin >> a >> b;
            cout << (pre[b] ^ pre[a-1]) << '\n';
        }
    }
}