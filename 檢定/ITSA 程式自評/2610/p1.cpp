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
    int a, b, c, d; char k;
    cin >> a >> k >> b >> k >> c >> k >> d;
    int total = a-(b*15+c*20+d*30);
    int aa, bb; aa = bb = 0;
    if (total < 0) {
        cout << 0 << '\n'; return 0;
    }
    while (total >= 50) aa++, total -= 50;
    while (total >= 5) bb++, total -= 5;
    cout << total << ',' << bb << ',' << aa << '\n';
}