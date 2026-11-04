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

struct Node {
    double w, e, t;
    int id;
};

signed main() { WA();
    int w, n, t; cin >> w >> n >> t;
    vector<Node> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].w >> v[i].e >> v[i].t;
        v[i].id = i;
    }
    sort(all(v), [&](Node a, Node b) {
        double va, vb;
        if (t == 1) va = a.e/a.w, vb = b.e/b.w;
        else va = a.t/a.w, vb = b.t/b.w;

        if (va == vb) return a.id < b.id;
        return va > vb;
    });
    vector<double> ans(n);
    double now = w, te = 0, tt = 0;
    for (auto &i : v) {
        if (now >= i.w) {
            ans[i.id] = i.w;
            te += i.e;
            tt += i.t;
            now -= i.w;
        }
        else {
            ans[i.id] = now;
            te += i.e*now/i.w;
            tt += i.t*now/i.w;
            now = 0;
            break;
        }
    }
    for (auto &i : ans) cout << fixed << setprecision(3) << i << ' ';
    cout << te << ' ' << tt << '\n';
}