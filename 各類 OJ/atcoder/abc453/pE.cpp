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
#define mod 998244353

vector<int> fac(200005), invF(200005);

inline int fpow(int a, int b) {
    int res = 1; a %= mod;
    for (; b; b >>= 1, a = a*a%mod) if (b&1) res = res*a % mod;
    return res;
}

inline int C(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fac[n]*invF[r] % mod * invF[n-r] % mod;
}

signed main() { WA();
    int n; cin >> n;

    fac[0] = 1;
    for (int i = 1; i <= 200000; i++) fac[i] = fac[i-1]*i % mod;
    invF[200000] = fpow(fac[200000], mod-2);
    for (int i = 199999; i >= 0; i--) invF[i] = invF[i+1]*(i+1) % mod;

    vector<int> a(n+2), b(n+2), u(n+2);
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        a[l]++, a[r+1]--;

        int lb = n-r, rb = n-l;
        b[max(1LL, lb)]++, b[min(n-1, rb)+1]--;

        vector<PII> v = {{l, r}, {lb, rb}}; sort(all(v));
        int cl = v[0].fi, cr = v[0].se;

        if (v[1].fi <= cr+1) {
            cr = max(cr, v[1].se);
            u[max(1LL, cl)]++, u[min(n-1, cr)+1]--;
        }
        else {
            u[max(1LL, cl)]++, u[min(n-1, cr)+1]--;
            u[max(1LL, v[1].fi)]++, u[min(n-1, v[1].se)+1]--;
        }
    }

    int ans, A, B, U; ans = A = B = U = 0;
    for (int k = 1; k < n; k++) {
        A += a[k], B += b[k], U += u[k];
        if (U == n) ans = (ans + C(A+B-n, k-(n-B))) % mod;
    }

    cout << ans;
}