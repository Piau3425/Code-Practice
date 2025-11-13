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
    int n, m; while (cin >> n >> m, n && m) {
        vector<tuple<int, int, int>> g;
        anc.assign(n, 0);
        iota(all(anc), 0);
        int total = 0, sum = 0;
        while (m--) {
            int a, b, w; cin >> a >> b >> w;
            g.pb({w, a, b}); total += w;
        }
        sort(all(g));
        for (auto &[w, a, b] : g) if (Union(a, b)) sum += w;
        cout << total-sum << '\n';
    }
}