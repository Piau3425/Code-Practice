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

mat mul(mat a, mat b) {
    mat c(a.size(), vector<int>(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

mat f(mat x, int k) {
    mat ret = {{1, 0}, {0, 1}};
    for (; k; k>>=1, x = mul(x, x)) if (k&1) ret = mul(ret, x);
    return ret;
}

signed main() { WA();
    int p, q, n; while (cin >> p >> q >> n) {
        if (!n) cout << "2\n";
        else {
            mat M = {{p, -q}, {1, 0}}, g = {{p}, {2}};
            cout << mul(f(M, n-1), g)[0][0] << '\n';
        }
    }
}