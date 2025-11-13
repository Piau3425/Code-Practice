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
    for (int T = 1; T <= t; T++) {
        cout << "Case #" << T << " : ";
        int v, e; cin >> v >> e;
        deque<tuple<int, int, int>> g, on, off;
        while (e--) {
            int a, b, w; cin >> a >> b >> w;
            a--, b--;
            g.pb({w, a, b});
        }
        sort(all(g));
        anc.assign(v, 0);
        iota(all(anc), 0);
        int sum = 0;
        vector<int> o(g.size());
        int idx = 0, cnt = 0;
        for (auto &[w, a, b] : g) {
            if (Union(a, b)) sum += w, o[idx] = true, cnt++;
            idx++;
        }
        int ans = INF;
        if (cnt == v-1) {
            for (int i = 0; i < o.size(); i++) {
                if (!o[i]) continue;
                iota(all(anc), 0);
                idx = sum = cnt = 0;
                for (auto &[w, a, b] : g) {
                    if (idx != i && Union(a, b)) sum += w, cnt++;
                    idx++;
                }
                if (cnt == v-1) ans = min(ans, sum);
            }
            if (ans != INF) cout << ans << '\n';
            else cout << "No second way\n";
        }
        else cout << "No way\n";            
    }
}