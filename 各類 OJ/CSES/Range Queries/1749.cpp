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

template<typename T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() { WA();
    int n; cin >> n; rbtree<int> t;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        t.insert(i);
    }
    for (; n--;) {
        int p; cin >> p;
        auto it = t.find_by_order(p-1);
        cout << v[*it] << (n ? " " : "");
        t.erase(it);
    }
}