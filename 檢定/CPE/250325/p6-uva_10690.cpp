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
    int x, y;
    while (cin >> x >> y) {
        vector<int> v(x+y);
        int sum = 0;
        for (auto &i : v) {
            cin >> i;
            sum += (i += 50);
        }

        if (x > y) swap(x, y);

        bitset<100*100+10> dp[x+1]; dp[0][0] = 1;
        for (int i = 0; i < x+y; i++) for (int j = x; j >= 1; j--) dp[j] |= (dp[j-1] << v[i]);

        int mx = -1e9, mn = 1e9;
        for (int i = 0; i <= sum; i++) if (dp[x][i]) {
            int k = (i-x*50) * (sum-i-y*50);
            mx = max(mx, k);
            mn = min(mn, k);
        }

        cout << mx << ' ' << mn << '\n';
    }
}