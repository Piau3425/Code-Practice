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
    int t, cas = 0; for (cin >> t; t--;) { cout << "Case " << ++cas << ": ";
        string s; cin >> s;
        int now = 0;
        char last;
        for (auto &c : s) {
            if (isdigit(c)) now = now*10 + c - '0';
            else {
                if (now) cout << string(now, last);
                now = 0;
                last = c;
            }
        }
        cout << string(now, last) << '\n';
    }
}