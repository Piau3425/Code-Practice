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
    return anc[x] == x ? x : anc[x] = Find(anc[x]);
}

void Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a > b) swap(a, b);
    if (a != b) anc[b] = a;
}

signed main() { WA();
    int n, r, T = 0;
    while (cin >> n >> r, n) { cout << "Scenario #" << ++T << '\n';
        vector<tuple<int, int, int>> g;
        map<string, int> mp;
        anc.assign(n, 0);
        iota(all(anc), 0);
        int idx = 0;
        while (r--) {
            string s; int a, b;
            cin >> s; if (mp.find(s) == mp.end()) mp[s] = idx++;
            a = mp[s];
            cin >> s; if (mp.find(s) == mp.end()) mp[s] = idx++;
            b = mp[s];
            int w; cin >> w;
            g.pb({w, a, b});
        }
        sort(all(g), greater<tuple<int, int, int>>());
        string s, e;
        int ans = -1;
        cin >> s >> e;
        for (auto &[w, a, b] : g) {
            Union(a, b);
            if (Find(mp[s]) == Find(mp[e])) {
                ans = w;
                break;
            }
        }
        cout << ans << " tons\n\n";
    }
}