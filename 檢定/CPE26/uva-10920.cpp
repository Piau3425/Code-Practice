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
    for (int sz, p; cin >> sz >> p, sz+p;) {
        int x = sz/2+1, y = sz/2+1;
        for (int i = 1; i <= sz; i += 2, x++, y++) {
            if (i*i >= p) {
                int now = i*i;
                for (int j = 0; j < i-1; j++) if (now > p) now--, y--;
                for (int j = 0; j < i-1; j++) if (now > p) now--, x--;
                for (int j = 0; j < i-1; j++) if (now > p) now--, y++;
                for (int j = 0; j < i-1; j++) if (now > p) now--, x++;
                break;
            }
        }
        cout << "Line = " << y << ", column = " << x << ".\n";
    }
}