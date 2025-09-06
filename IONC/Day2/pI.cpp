#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n, k;
    while (cin >> n >> k) {
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        int prod = 1, ans = 0;
        for (int l = 0, r = 0; r < n; r++) {
            prod *= v[r];
            while (prod > k) prod /= v[l++];
            ans += r-l+1;
            cout << l << ' ' << r << ' ' << r-l+1 << '\n';
        }
        cout << ans << '\n';
    }
}