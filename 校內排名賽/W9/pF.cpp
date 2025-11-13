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

/*
1+2+3 + ... + n = n(n+1)/2;
sum - 2x = k;
sum - k = 2x
*/


signed main() { WA();
    int t; for (cin >> t; t--;) {
        int i = 1, s, k, n; s = k = 0; cin >> n;
        n = abs(n);
        for (; !(s >= n && !(s-n & 1)); i++) s += i;
        if (i-1) cout << i-1 << '\n';
        else cout << 3 << '\n';
        if (t) cout << '\n';
    }
}