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
    int n, t = 0;
    while (cin >> n, n) {
        int ans = 0;
        vector<int> v(n), bit(n+1);
        map<int, int> des;
        for (auto &i : v) cin >> i, des[i] = 1;
        int idx = 1;
        for (auto &i : des) i.se = idx++;
        for (auto &i : v) i = des[i];
        for (int i = 0; i < n; i++) {
            int k = 0;
            for (int j = v[i]; j; j -= j&-j) k += bit[j];
            ans += i - k;
            for (int j = v[i]; j <= n; j += j&-j) bit[j]++;
        }
        cout << "Case #" << ++t << ": " << ans << '\n';
    }
}
