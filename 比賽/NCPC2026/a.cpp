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
#define TIII tuple<int, int, int>

signed main() { WA();
    int t; for (cin >> t; t--;) {
        int n, k; cin >> n >> k;
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        int a, b, now; a = b = 0; now = 1;
        for (int i = 1; i < n; i++) {
            if (v[i] > v[i-1]) now++;
            else {
                if (now >= k && now > 1) a++;
                now = 1;
            }
        }
        if (now >= k && now > 1) a++;
        reverse(all(v));
        now = 1;
        for (int i = 1; i < n; i++) {
            if (v[i] > v[i-1]) now++;
            else {
                if (now >= k && now > 1) b++;
                now = 1;
            }
        }
        if (now >= k && now > 1) b++;
        cout << a << ' ' << b << '\n';
    }
}