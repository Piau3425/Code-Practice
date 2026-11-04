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
    vector<vector<PII>> v(n, vector<PII>(n)), to = v;
    for (auto &i : to) for (auto &j : i) cin >> j.fi;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v[i][j].fi = i*n+j+1;
        }
    }
    int flag = 1;
    for (int i = 0; i < n && flag; i++) for (int j = 0; j < n && flag; j++) {
        if (v[i][j] == to[i][j]) v[i][j].se = to[i][j].se = -1;
        else for (int k = 0; k < n; k++) {
            if (v[i][j] == to[k][j]) v[i][j].se = to[k][j].se = 1;
            else if (v[i][j] == to[i][k]) v[i][j].se = to[i][k].se = 2;
        }
        if (v[i][j].se == 0) flag = 0;
    }
    for (int i = 0; i < n; i++) {
        vector<int> a, b;
        for (int j = 0; j < n; j++) {
            if (v[i][j].se == 2) a.pb(v[i][j].fi);
            if (to[i][j].se == 2) b.pb(to[i][j].fi);
        }
        if (a != b) flag = 0;
    }
    for (int i = 0; i < n; i++) {
        vector<int> a, b;
        for (int j = 0; j < n; j++) {
            if (v[j][i].se == 1) a.pb(v[j][i].fi);
            if (to[j][i].se == 1) b.pb(to[j][i].fi);
        }
        if (a != b) flag = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j].se == -1) {
                int a, b, c, d; a = b = c = d = 0;
                for (int k = 0; k < n; k++) {
                    if (v[i][k].se == 2 && k < j) a++;
                    if (to[i][k].se == 2 && k < j) b++;
                }
                for (int k = 0; k < n; k++) {
                    if (v[k][j].se == 1 && k < i) c++;
                    if (to[k][j].se == 1 && k < i) d++;
                }
                if (a != b && c != d) flag = 0;
            }
        }
    }
    if (flag) cout << "Yes\n";
    else cout << "No\n";
}