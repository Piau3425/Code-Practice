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

map<char, double> mp = {
    {'C', 12.01},
    {'H', 1.008},
    {'O', 16},
    {'N', 14.01}
};

signed main() { WA();
    int t; for (cin >> t; t--;) {
        string s; cin >> s;
        char ele = '~'; double sum = 0, now = 0;
        for (auto &c : s) {
            if (isdigit(c)) {
                now = now*10+c-'0';
            }
            else {
                if (now != '~') sum += mp[ele]*max(1.0, now);
                ele = c;
                now = 0;
            }
        }

        cout << fixed << setprecision(3) << sum + mp[ele]*max(1.0, now) << '\n';
    }
}