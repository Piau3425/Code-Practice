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

int n, m;

mat mul(mat a, mat b) {
    mat c(a.size(), vector<int>(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                c[i][j] = (c[i][j] + a[i][k]*b[k][j] % (1<<m)) % (1<<m);
            }
        }
    }
    return c;
}

mat f(mat k, int x) {
    mat ret = {{1, 0}, {0, 1}};
    for (; x; x>>=1, k = mul(k, k)) if (x&1) ret = mul(ret, k);
    return ret;
}

signed main() { WA();
    while (cin >> n >> m) if (!n) cout << "0\n"; else cout << mul(f({{1, 1}, {1, 0}}, n-1), {{1}, {0}})[0][0] << '\n';
}