#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    vector<vector<PII>> v(3, vector<PII>(2));
    for (int i = 0; i < 3; i++) {
        cin >> v[i][0].fi >> v[i][1].fi >> v[i][0].se >> v[i][1].se;
        if (v[i][0].fi > v[i][0].se) {
            swap(v[i][0].fi, v[i][0].se);
            swap(v[i][1].fi, v[i][1].se);
        }
    }
    sort(all(v));
    int flag = 0;
    if (v[0][0].fi <= v[1][0].se && v[0][0].se >= v[1][0].fi   &&   v[0][1].fi <= v[1][1].se && v[0][1].se >= v[1][1].fi) flag = 1;
    if (v[1][0].fi <= v[2][0].se && v[1][0].se >= v[2][0].fi   &&   v[1][1].fi <= v[2][1].se && v[1][1].se >= v[2][1].fi) flag = 1;
    if (v[0][0].fi <= v[2][0].se && v[0][0].se >= v[2][0].fi   &&   v[0][1].fi <= v[2][1].se && v[0][1].se >= v[2][1].fi) flag = 1;
    if (flag) cout << "T\n";
    else cout << "F\n";
}   