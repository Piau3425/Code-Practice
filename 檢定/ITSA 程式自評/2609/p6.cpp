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
    int t; for (cin >> t; t--;) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        sort(all(v), greater<int>());
        int sum = 0;
        for (auto &i : v) {
            int rank = lower_bound(all(v), i, greater<int>())-v.begin();
            //cout << i << ' ' << rank << ' ';
            rank = (100*rank+n-1)/n;
            //cout << rank << '\n';
            if (rank <= 10) sum += i*4;
            else if (rank <= 30) sum += i*3;
            else if (rank <= 60) sum += i*2;
            else if (rank <= 80) sum += i*1;
        }
        cout << (sum+5)/10 << '\n';
    }
}