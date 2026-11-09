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
    int n; for (cin >> n; n--;) {
        int x, i = 9; cin >> x;
        if (x == 1) {
            cout << "1\n";
            continue;
        }
        string s;
        while (i > 1) {
            while (!(x%i)) s += i+'0', x/=i;
            i--;
        }
        sort(all(s));
        if (s.size() && x == 1) cout << s << '\n';
        else cout << "-1\n";
    }
}