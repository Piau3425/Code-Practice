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

template<typename T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() { WA();
    for (int p, e, i, d, t = 0; cin >> p >> e >> i >> d, ~p&&~e&&~i&&~d;) {
        int j = d+1;
        for (; (j-p)%23 || (j-e)%28 || (j-i)%33; j++);
        cout << "Case " << ++t << ": the next triple peak occurs in " << j-d << " days.\n";
    }
}