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
    int n, k; while (cin >> n >> k) {
        vector<int> v(n+1); int l, r; l = r = 0;
        for (auto &i : v) cin >> i, r += i, l = max(l, i);
        while (l < r) {
            int m = l + ((r-l)>>1), now = 0, cnt = 1;
            for (auto &i : v) {
                if (now+i > m) cnt++, now = 0;
                now += i;
            }
            if (cnt > k+1) l = m+1;
            else r = m;
        }
        cout << l << '\n';
    }
}