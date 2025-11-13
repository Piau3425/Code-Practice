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
#define mat vector<vector<int>>

/*
f(n, 0, XL) = f(n-1, 0, .P) + f(n-1, 1, .A)
f(n, 0, LL) = f(n-1, 0, XL)
f(n, 0, .P) = f(n-1, 0, XL+LL+.A+.P)
f(n, 1, XL) = f(n-1, 1, .A+.P)
f(n, 1, LL) = f(n-1, 1, XL)
f(n, 1, .A) = f(n-1, 0, XL+LL+.P)
f(n, 1, .P) = f(n-1, 1, XL+LL+.A+.P)

f(n, 0, XL) | 0 0 0 1 0 0 1 0 | f(n-1, 0, XL)
f(n, 0, LL) | 1 0 0 0 0 0 0 0 | f(n-1, 0, XL)
f(n, 0, .P) | 0 0 0 0 1 1 1 1 | f(n-1, 0, P)
f(n, 1, XL) | 0 0 0 0 0 0 1 1 | f(n-1, 1, XL)
f(n, 1, LL) | 0 0 0 0 1 0 0 0 | f(n-1, 1, LL)
f(n, 1, .A) | 1 1 0 1 0 0 0 0 | f(n-1, 1, .A)
f(n, 1, .P) | 0 0 0 0 1 1 1 1 | f(n-1, 1, .P)
*/

int p = 1e9+7;

mat mul(mat a, mat b) {
    mat c(a.size(), vector<int>(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                c[i][j] = (c[i][j] + a[i][k]*b[k][j]%p)%p;
            }
        }
    }
    return c;
}

mat f(mat k, int x) {
    mat ret = {

    };
    for (; x; x>>=1, k = mul(k, k)) if (x&1) ret = mul(ret, k);
    return ret;
}

signed main() { WA();
    for (int n; cin >> n;) {
        mat result = mul(f({

        }, n-1), {});
        int ans = 0;
        for (int i = 0; i < 7; i++) ans = (ans + result[i][0])%p;
        cout << ans << '\n';
    }
}