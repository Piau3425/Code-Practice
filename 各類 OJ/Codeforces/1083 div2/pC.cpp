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

bitset<1000005> bs, inE;

signed main() { WA();
    int t;
    for (cin >> t; t--;) {
        int n; cin >> n;
        vector<vector<int>> e(n);

        for (int i = 0; i < n; i++) {
            int l; cin >> l;
            vector<int> a(l); for (auto &x : a) cin >> x;
            for (int j = l-1; j+1; j--) if (!inE[a[j]]) e[i].pb(a[j]), inE[a[j]] = 1;
            for (auto x : e[i]) inE[x] = 0;
        }
        
        vector<int> picked(n, 0), ans;
        
        for (int step = 0; step < n; step++) {
            int id = -1;
            for (int i = 0; i < n; i++) if (!picked[i]) {
                if (!~id) { id = i; continue; }
                int p1 = 0, p2 = 0, sz1 = e[i].size(), sz2 = e[id].size(), isB = 0;
                while (1) {
                    while (p1 < sz1 && bs[e[i][p1]]) p1++;
                    while (p2 < sz2 && bs[e[id][p2]]) p2++;
                    if (p1 == sz1 && p2 == sz2) break;
                    if (p1 == sz1) { isB = 1; break; }
                    if (p2 == sz2) break;
                    if (e[i][p1] != e[id][p2]) { isB = e[i][p1] < e[id][p2]; break; }
                    p1++, p2++;
                }
                if (isB) id = i;
            }
            picked[id] = 1;
            for (auto x : e[id]) if (!bs[x]) ans.pb(x), bs[x] = 1;
        }

        for (auto &x : ans) cout << x << " \n"[&x == &ans.back()], bs[x] = 0;
    }
}