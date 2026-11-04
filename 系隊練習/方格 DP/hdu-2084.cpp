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

template<typename T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() { WA();
    int t; for (cin >> t; t--;) {
        int n; cin >> n;
        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) cin >> v[i][j];
        }
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                v[i][j] += max(v[i+1][j], v[i+1][j+1]);
            }
        }
        cout << v[0][0] << '\n';
    }
}