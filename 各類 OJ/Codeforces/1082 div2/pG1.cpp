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
    int t; for (cin >> t; t--;) {
        int n, q; cin >> n >> q;
        vector<int> degR(n+1, 0), degC(n+1, 0), pos(n+2, 1), diff(n+2, 0);
        int nz = 0;

        while (q--) {
            int r, c; cin >> r >> c;
            int i1 = pos[degR[r]]++; degR[r]++;
            nz -= diff[i1] != 0, diff[i1]++, nz += diff[i1] != 0;

            int i2 = ++degC[c];
            nz -= diff[i2] != 0, diff[i2]--, nz += diff[i2] != 0;

            if (nz) cout << "NO\n"; else cout << "YES\n";
        }
    }
}