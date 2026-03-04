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
    for (int n; cin >> n, n;) {
        vector<int> v(n);
        int avg = 0;
        for (auto &i : v) {
            double k; cin >> k;
            i = k*100+0.5;
            avg += i;
        }
        avg /= n;
        

        int ans, a = 0, b = 0;
        for (auto &i : v) {
            if (i < avg) a += avg-i;
            else if (i > avg+1) b += i-avg-1;
        }
        ans = max(a, b);
        cout << '$' << ans/100 << '.' << setw(2) << setfill('0') << ans%100 << '\n';
    }
}