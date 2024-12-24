#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

vector<int> anc;


int Find(int x) {
    return (anc[x] == x ? x : anc[x] = Find(anc[x]));
}

void Union(int a, int b) {
    int fa = Find(a), fb = Find(b);
    if (fa != fb) anc[fb] = fa;
}

signed main() { WA();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        anc.resize(n);
        iota(all(anc), 0);
        vector<pair<double, double>> v(n);
        vector<tuple<double, double, double>> g;
        for (auto &i : v) cin >> i.fi >> i.se;
        for (int i = 0; i+1 < n; i++) for (int j = i + 1; j < n; j++) {
                g.push_back({sqrt((v[j].fi-v[i].fi)*(v[j].fi-v[i].fi)+(v[j].se-v[i].se)*(v[j].se-v[i].se)), i, j});
        }
        sort(all(g));

        double ans = 0;
        for (auto v : g) {
            auto [dis, a, b] = v;
            if (Find(a) != Find(b)) {
                ans += dis;
                Union(a, b);
            }
        }

        cout << fixed << setprecision(2) << ans << '\n';
        if (t) cout << '\n';
    }
}