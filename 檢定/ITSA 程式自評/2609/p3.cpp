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
        int a, b, c; cin >> a >> b >> c;
        if (a >= 60 && b >= 60 && c >= 60) cout << "P\n";
        else if ((a<60)+(b<60)+(c<60) == 1) {
            if (a+b+c >= 220) cout << "P\n";
            else cout << "M\n";
        }
        else if (((a >= 80) + (b >= 80) + (c >= 80) == 1) && ((a<60)+(b<60)+(c<60) == 2)) cout << "M\n";
        else cout << "F\n";
    }
}