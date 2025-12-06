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
    for (int s, c; cin >> s >> c, s+c;) {
        map<string, int> mp;
        vector<tuple<int, int, int>> g;
        anc.assign(s, 0); iota(all(anc), 0);
        int id = 0;
        for (string str; s--;) cin >> str, mp[str] = id++;
        while (c--) {
            string a, b; int w;
            cin >> a >> b >> w;
            g.pb({w, mp[a], mp[b]});
        }
        sort(all(g)); int ans = 0;
        for (auto &[w, a, b] : g) if (Union(a, b)) ans += w;
        int possible = 1;
        string start; cin >> start;
        for (auto &i : anc) if (Find(i) != Find(mp[start])) possible = 0;
        if (possible) cout << ans << '\n';
        else cout << "Impossible\n";
    }
}