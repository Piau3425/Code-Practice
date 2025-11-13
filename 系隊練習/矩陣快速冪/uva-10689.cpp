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

int a, b, n, m, p;

mat mul(mat a, mat b) {
    mat c(a.size(), vector<int>(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j] % p) %p;
            }
        }
    }
    return c;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
}

mat f(mat k, int x) {
    mat t = {{1, 0}, {0, 1}};
    for (; x; x>>=1, k = mul(k, k)) if (x&1) t = mul(t, k);
    return t;
}

signed main() { WA();
    int t; cin >> t;
    while (t--) {
        cin >> a >> b >> n >> m; p = 1;
        for (; m--;) p *= 10; a %= p, b %= p;
        cout << mul(f({{1, 1}, {1, 0}}, n-1), {{b}, {a}})[0][0] << '\n';
    }
}