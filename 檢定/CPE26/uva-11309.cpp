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
        int a, b; char c; cin >> a >> c >> b;
        for (string s, k;;) { b++;
            if (b >= 60) b = 0, a++;
            if (a >= 24) a = 0;
            if (s = to_string(a*100+b), k = string(s.rbegin(), s.rend()), s == k) break;
        }
        cout << setfill('0') << setw(2) << a << ':' << setfill('0') << setw(2) << b << '\n';
    }
}