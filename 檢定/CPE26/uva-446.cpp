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
        string a, b; char c;
        cin >> a >> c >> b;
        bitset<13> aa(stoi(a, 0, 16)), bb(stoi(b, 0, 16));
        int ans;
        if (c == '+') ans = stoi(a, 0, 16) + stoi(b, 0, 16);
        else ans = stoi(a, 0, 16) - stoi(b, 0, 16);
        cout << aa << ' ' << c << ' ' << bb << " = " << ans << '\n';
    }
}