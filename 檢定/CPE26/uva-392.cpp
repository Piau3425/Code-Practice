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
    for (;;) {
        vector<int> v(9); for (auto &i : v) cin >> i;
        if (!cin) break;
        int flag = 0;
        for (int i = 0; i < 9; i++) {
            if (v[i]) {
                if (v[i] < 0) {
                    if (flag) cout << " - ";
                    else cout << "-";
                }
                else if (flag) cout << " + ";
                flag = 1;
                if (abs(v[i]) != 1 || i == 8) cout << abs(v[i]);
                if (i < 8) cout << "x";
                if (i < 7) cout << "^" << 8-i;
            }
        }
        if (!flag) cout << 0;
        cout << '\n';
    }
}