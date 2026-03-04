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
    int t;
    for (cin >> t; t--;) {
        int n; cin >> n;
        vector<int> a(n+1); for (int i = 1; i <= n; i++) cin >> a[i];
        
        int ans = n*(n+1)*(n+2)/6;
        vector<PII> stk;
        for (int i = n; i; i--) {
            while (stk.size() && stk.back().fi == a[i]+1)
                ans -= i*(n-stk.back().se+1), stk.pop_back();
            stk.emplace_back(a[i], i);
        }
        cout << ans << '\n';
    }
}