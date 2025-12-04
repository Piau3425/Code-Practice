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
    for (int n; cin >> n;) {
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        sort(all(v));
        int k; cin >> k;
        int a, b;
        for (int ldx = 0, rdx = n-1; ldx < rdx;) {
            if (v[ldx] + v[rdx] < k) ldx++;
            else if (v[ldx] + v[rdx] > k) rdx--;
            else a = v[ldx], b = v[rdx], ldx++, rdx--;
        }
        cout << "Peter should buy books whose prices are " << a << " and " << b << ".\n\n";
    }
}