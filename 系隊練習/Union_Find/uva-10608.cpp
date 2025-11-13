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
    if (a == b) return;
    if (a > b) swap(a, b);
    anc[b] = a;
}

signed main() { WA();
    int t; for (cin >> t; t--;) {
        int n, m; cin >> n >> m;
        anc.assign(n+1, 0);
        iota(all(anc), 0);
        while (m--) {
            int a, b; cin >> a >> b;
            Union(a, b);
        }
        multiset<int> s;
        for (int i = 1; i <= n; i++) s.insert(Find(i));
        int mx = -1e9;
        for (int i = 1; i <= n; i++) mx = max(mx, (int)s.count(i));
        cout << mx << '\n';
    }
}