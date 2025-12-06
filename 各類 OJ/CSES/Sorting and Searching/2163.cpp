#include <bits/stdc++.h>
#include <bits/extc++.h>
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

signed main() { WA();
    int n, k; cin >> n >> k;
    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> t;
    for (int i = 1; i <= n; i++) t.insert(i);
    int now = 0; while (t.size()) {
        now = (now+k)%t.size();
        cout << *t.find_by_order(now) << ' ';
        t.erase(t.find_by_order(now));
    }
}