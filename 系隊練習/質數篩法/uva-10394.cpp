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
#define MAXN 20000001

signed main() { WA();
    vector<int> isp(MAXN, 1), ps;
    for (int i = 2; i <= MAXN; i++) {
        if (isp[i]) ps.pb(i);
        for (auto p : ps) {
            if (p*i > MAXN) break;
            isp[i*p] = 0;
            if (!(i%p)) break;
        }
    }
    vector<PII> lst; int n;
    for (int i = 0; i+1 < ps.size(); i++) if (ps[i]+2 == ps[i+1]) lst.pb({ps[i], ps[i+1]});
    while (cin >> n) printf("(%d, %d)\n", lst[n-1].fi, lst[n-1].se);
}