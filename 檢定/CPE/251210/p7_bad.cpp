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

void Union(int a, int b) {
    a = Find(a), b = Find(b);
    anc[b] = a;
}

signed main() { WA();
    for (int n, m; cin >> n >> m;) {
        vector<vector<int>> v(n);
        anc.assign(n, 0); iota(all(anc), 0);
        for (int k = m; k--;) {
            char c; int a, b;
            cin >> c >> a >> c >> b >> c;
            v[a].pb(b);
            v[b].pb(a);
            Union(a, b);
        }
        int mn = INF, all = 1;
        set<int> st;
        for (auto &i : v) mn = min(mn , (int)i.size());
        for (int i = 0; i < n; i++) {
            if (v[i].size() != n-1) all = 0;
            st.insert(Find(i));
        }
        if (n == 0 || st.size() > 1) cout << "0\n";
        else if (all) cout << n << '\n';
        else cout << mn << '\n';
    }
}