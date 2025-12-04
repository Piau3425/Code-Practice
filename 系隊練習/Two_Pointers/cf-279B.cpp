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
    for (int n, k; cin >> n >> k;) {
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        int ans = 0;
        for (int ldx = 0, rdx = 0, sum = 0; rdx < n; rdx++) {
            sum += v[rdx];
            while (sum > k) sum -= v[ldx++];
            ans = max(ans, rdx-ldx+1);
        }
        cout << ans << '\n';
    }
}