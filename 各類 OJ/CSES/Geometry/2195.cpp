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

__int128 cross(PII o, PII a, PII b) {
    return ((__int128)a.fi - o.fi) * ((__int128)b.se - o.se)
         - ((__int128)a.se - o.se) * ((__int128)b.fi - o.fi);
}
vector<PII> hull(vector<PII> pts) {
    sort(all(pts));
    pts.erase(unique(all(pts)), pts.end());
    int n = pts.size();
    if (n < 3) return pts;
    vector<PII> h(2 * n); int k = 0;
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(h[k - 2], h[k - 1], pts[i]) < 0) k--;
        h[k++] = pts[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross(h[k - 2], h[k - 1], pts[i]) < 0) k--;
        h[k++] = pts[i];
    }
    h.resize(k - 1);
    return h;
}

signed main() { WA();
    int n; cin >> n;
    vector<PII> v(n);
    for (auto &i : v) cin >> i.fi >> i.se;
    v = hull(v);
    cout << v.size() << '\n';
    for (auto &i : v) cout << i.fi << ' ' << i.se << '\n';
}