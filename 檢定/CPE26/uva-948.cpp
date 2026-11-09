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
    vector<int> fib = {1, 1};
    while (fib.back() <= 100000000) fib.pb(fib[fib.size()-1]+fib[fib.size()-2]);
    int n; for (cin >> n; n--;) {
        int x; cin >> x;
        cout << x;
        string s;
        for (auto it = prev(upper_bound(all(fib), x)); it != fib.begin(); it--) {
            if (x>=*it) s += '1', x-=*it;
            else if (s.size()) s += '0';
        }
        cout << " = " << s << " (fib)\n";
    }
}