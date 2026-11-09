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
    for (int n; cin >> n, n;) {
        char c; cin >> c;
        int flag = 1;
        vector<int> v(n), pos(n);
        for (auto &i : v) cin >> i, pos[i] = &i-v.data();
        for (int i = 0; i < n && flag; i++) {
            for (int j = i+1; j < n && flag; j++) {
                int k = 2*v[j]-v[i];
                if (k >= 0 && k < n && pos[k] > j) flag = 0;
            }
        }
        cout << (flag ? "yes" : "no") << '\n';
    }
} 