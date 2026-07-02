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

int f(int a, int b, int &x, int &y) {
    if (!b) return x = 1, y = 0, a;
    int ret = f(b, a%b, y, x);
    y = y - (a/b) * x;
    return ret;
}

signed main() { WA();
    for (int a, b; cin >> a >> b;) {
        int x, y, k = f(a, b, x, y);
        cout << x << ' ' << y << ' ' << k << '\n';
    }
}