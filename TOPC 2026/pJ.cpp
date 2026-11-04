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
    set<int> st;
    vector<int> v;
    for (int i = 1; i < LONG_LONG_MAX/10; i <<= 1) v.pb(i);
    for (auto &i : v) for (auto &j : v) st.insert(i+j);
    int t; for (cin >> t; t--;) {
        int x; cin >> x;
        int ans = LONG_LONG_MAX;
        for (auto &i : st) ans = min(ans, abs(i-x));
        cout << ans << '\n';
    }
}