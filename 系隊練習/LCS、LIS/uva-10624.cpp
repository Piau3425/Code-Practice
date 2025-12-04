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
        for (auto &i : v) cin >> i;
        int a, b, c, d; a = b = c = d = 0;
        for (auto &i : v) {
            c += i;
            d = max(0LL, d+i);
            a = max(a, c);
            b = max(b, d);
        }
        a = max(a, b);
        if (a > 0) cout << "The maximum winning streak is " << a << ".\n";
        else cout << "Losing streak.\n";
    }
}