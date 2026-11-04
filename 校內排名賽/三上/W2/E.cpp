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

vector<int> p(1000005, 1), ppp;

signed main() { WA();
    p[0] = p[1] = false;
    for (int i = 2; i < 1000005; i++) {
        if (p[i]) {
            for (int j = i*i; j < 1000005; j += i) p[j] = false;
            for (int j = i*i; j < 1000000000005; j *= i) ppp.pb(j);
        }
    }
    sort(all(ppp));
    int t; for (cin >> t; t--;) {
        int a, b; cin >> a >> b;
        cout << upper_bound(all(ppp), b) - lower_bound(all(ppp), a)<< '\n';
    }
}