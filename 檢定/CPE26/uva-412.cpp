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
    for (int n; cin >> n, n;) {
        int x = n*(n-1)/2, y = 0;
        vector<int> v(n); for (auto &i : v) cin >> i;
        for(int i = 0; i < v.size()-1; i++) for(int j = i+1; j < v.size(); j++) if(__gcd(v[i], v[j]) == 1) y++;
        if (y) cout << fixed << setprecision(6) << sqrt(6.0*x/y) << '\n';
        else cout << "No estimate for this data set.\n";
    }
}