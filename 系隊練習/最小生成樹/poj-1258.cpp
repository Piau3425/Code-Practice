#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define pb push_back
#define fi first
#define se second
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

signed main() {
    for (int n; cin >> n;) {
        vector<vector<int> > v(n, vector<int>(n));
        vector<pair<int, pair<int, int> > > g;
        anc.assign(n, 0);
        for (int i = 0; i < n; i++) anc[i] = i;
        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> v[i][j];
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                g.pb(make_pair(v[i][j], make_pair(i, j)));
            }
        }
        sort(all(g)); int ans = 0;
        for (int i = 0; i < g.size(); i++) {
            if (Union(g[i].se.fi, g[i].se.se)) ans += g[i].fi;
        }
        cout << ans << '\n';
    }
}