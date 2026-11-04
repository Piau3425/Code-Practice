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
    int n; cin >> n;
    vector<PII> v(n);
    for (auto &i : v) cin >> i.fi >> i.se;
    sort(all(v));
    priority_queue<int, vector<int>, greater<int>> pq;
    int time = 0, mx = -INF;
    for (auto &i : v) {
        int a, b; tie(a, b) = i;
        while (pq.size() && pq.top() <= a) pq.pop();
        pq.push(b);
        mx = max(mx, (int)pq.size());
    }
    cout << mx << '\n';
}