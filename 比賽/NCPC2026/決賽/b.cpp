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
    int n, m; cin >> n >> m;
    vector<int> d(1005, INF);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (d[x] != INF) d[x] = i;
    }
    vector<PII> item(m);
    for (auto &i : item) cin >> i.fi >> i.se;
    vector<int> week(n+1);
    for (int i = 0; i < m; i++) {
        int query; cin >> query;
        int price = item[i].se, swk = item[i].fi, target = price - query;
        if (target <= 0) {
            week[swk] += price;
            continue;
        }
        int mn = INF, ans;
        for (int i = target; i <= 1000; i++) {
            if (d[i] < mn) {
                ans = i;
                mn = d[i];
            }
        }
        if (mn != INF && swk-1+mn <= n) week[swk-1+mn] += max(0LL, price-ans);
    }
    //for (auto &i : week) cout << i << ' '; cout << '\n';
    cout << *max_element(all(week)) << '\n';
}