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
    cout << "Lumberjacks:\n";
    int n; for (cin >> n; n--;) {
        vector<int> v(10), k; for (auto &i : v) cin >> i;
        k = v; sort(all(k));
        int i, j; i = j = 0;
        for (; i < 10; i++) if (v[i] != k[i]) break;
        reverse(all(k));
        for (; j < 10; j++) if (v[j] != k[j]) break;
        if (i == 10 || j == 10) cout << "Ordered\n";
        else cout << "Unordered\n";
    }
}