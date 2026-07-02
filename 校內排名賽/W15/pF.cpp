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
    for (int x, y, w, h, t = 0; cin >> x >> y >> w >> h;) { if (t++) cout << '\n';
        vector<vector<int>> v(h+1);
        for (int i = h; i; i--) {
            int n; cin >> n;
            while (n--) {
                int sx; cin >> sx;
                int dx = sx - x, dy = i - y, nx = sx, ny = i;
                if (dy >= dx && dy > -dx) ny++;
                else if (dy < dx && dy >= -dx) nx++;
                else if (dy <= dx && dy < -dx) ny--;
                else nx--;
                if (nx >= 1 && nx <= w && ny >= 1 && ny <= h) v[ny].pb(nx);
            }
        }
        cout << x << ' ' << y << ' ' << w << ' ' << h << '\n';
        for (int i = h; i; i--) {
            sort(all(v[i]));
            cout << v[i].size();
            for (auto &j : v[i]) cout << ' ' << j;
            cout << '\n';
        }
    }
}