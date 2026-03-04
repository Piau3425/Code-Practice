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
#define MAXN 5000005

vector<int> wl, wr, ct, cf, cs;
vector<int> anc;
int dep;

void build(int l, int r) {
    if (l > r) return;
    int m = (l+r) >> 1;
    wl[m] = r-m, wr[m] = m-l;
    for (int k = 0; k < dep; k++) {
        auto [i, j] = minmax(anc[k], m);
        ct[j-i]++, cf[wl[i]+wr[j]+2]++;
    }
    anc[dep++] = m;
    build(l, m-1), build(m+1, r);
    dep--;
}

signed main() { WA();
    int n; cin >> n;
    wl.assign(n+1, 0); wr.assign(n+1, 0);
    ct.assign(2*n+2, 0); cf.assign(2*n+2, 0); cs.assign(2*n+2, 0);
    anc.assign(n+1, 0); dep = 0;
    build(1, n);

    vector<int> u; bitset<MAXN> bs(0);
    for (int i = 1; i <= n; i++) if (!bs[wl[i]]) bs[wl[i]] = 1, u.pb(wl[i]);

    vector<int> cnt(n+1, 0);
    for (int j = 1; j <= n; j++) {
        for (auto &v : u) if (cnt[v]) cs[v+wr[j]+2] += cnt[v];
        cnt[wl[j]]++;
    }

    vector<int> ans(n+1, 0);
    for (int i = 0; i <= n*2; i++) {
        int res = cs[i] - cf[i] + ct[i];
        if (i <= n) ans[n-i] += res;
    }

    for (int k = 0; k <= n; k++) cout << ans[k] << " \n"[k == n];
}