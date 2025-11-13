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

vector<int> anc;

int Find(int x) {
    return x == anc[x] ? x : anc[x] = Find(anc[x]);
}

bool Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return false;
    if (a > b) swap(a, b);
    return anc[b] = a, true;
}

signed main() { WA();
    int t; cin >> t;
    while (t--) {
        int s, p; cin >> s >> p;
        vector<PII> v(p);
        for (auto &i : v) cin >> i.fi >> i.se;
        vector<tuple<double, int ,int>> g;
        for (int i = 0; i < p; i++) for (int j = i+1; j < p; j++) g.pb({hypot(v[i].fi-v[j].fi, v[i].se-v[j].se), i, j});
        sort(all(g));
        anc.assign(p, 0);
        iota(all(anc), 0);
        deque<double> k;
        for (auto &[w, a, b] : g) if (Union(a, b)) k.pb(w);
        cout << fixed << setprecision(2) << k[p-s-1] << '\n';
    }
}