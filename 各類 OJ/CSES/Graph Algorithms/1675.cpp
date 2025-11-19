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
#define TIII tuple<int, int, int>

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
    int n, m; cin >> n >> m;
    anc.assign(n+1, 0);
    iota(all(anc), 0);
    vector<TIII> g;
    while (m--) {
        int a, b, w; cin >> a >> b >> w;
        g.pb({w, a, b});
    }
    sort(all(g));
    int ans = 0;
    for (auto &[w, a, b] : g) if (Union(a, b)) ans += w;
    set<int> st;
    for (auto &i : anc) st.insert(Find(i));
    if (st.size() == 2) cout << ans << '\n';
    else cout << "IMPOSSIBLE\n";
}