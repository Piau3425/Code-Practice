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
    for (int n; cin >> n;) {
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        int sum; cin >> sum;
        sort(all(v));
        int l = 0, r = v.size()-1;
        int ll, rr;
        while (l < r) {
            if (v[l] + v[r] < sum) l++;
            else if (v[l] + v[r] > sum) r--;
            else ll = v[l], rr = v[r], l++, r--;
        }
        cout << "Peter should buy books whose prices are " << ll << " and " << rr << ".\n\n";
    }
}