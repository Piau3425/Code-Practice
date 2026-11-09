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
        int x, y, now;
        for (int i = 1; i < 100000; i++) {
            if (i*i >= n) {
                x = y = i; now = i*i-i+1;
                while (now < n) now++, y--;
                while (now > n) now--, x--;
                if (i&1) swap(x, y);
                break;
            }
        }
        cout << x << ' ' << y << '\n';
    }
}