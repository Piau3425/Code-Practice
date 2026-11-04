#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>
#define TIII tuple<int, int, int>
#define mat vector<vector<int>>

template<typename T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mat mul(mat a, mat b) {
    int n = a.size(), m = b[0].size(), K = b.size();
    mat c(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int k = 0; k < K; k++) {
            if (!a[i][k]) continue;
            for (int j = 0; j < m; j++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]);
        }
    return c;
}

mat f(mat k, int x) {
    mat ret = {{1, 0}, {0, 1}};
    for (; x; x>>=1, k = mul(k, k)) if (x&1) ret = mul(ret, k);
    return ret;
}

signed main() { WA();
    for (int p, q, n; cin >> p >> q >> n;) {
        if (!n) cout << "2\n";
        else {
            mat a = {{p, -q}, {1, 0}}, b = {{p}, {2}};
            cout << mul(f(a, n-1), b)[0][0] << '\n';
        }
    }
}