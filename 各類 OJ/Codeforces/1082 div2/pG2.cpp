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
    int t;
    for (cin >> t; t--;) {
        int n, q; cin >> n >> q;
        vector<int> degR(n+2, 0), degC(n+2, 0), csp(n+2, 0);
        int sumR2 = 0, sumC2 = 0;
        
        for (; q--;) {
            int r, c; cin >> r >> c;

            sumR2 += 2*degR[r] + 1; degR[r]++;
            sumC2 += 2*csp[degC[c]+1] + 1; csp[++degC[c]]++;
            
            cout << (sumR2 == sumC2 ? "YES\n" : "NO\n");
        }
    }
}