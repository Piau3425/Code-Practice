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

vector<int> anc, sz;

int Find(int x) {
    return x == anc[x] ? x : anc[x] = Find(anc[x]);
}

void Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return;
    if (a > b) swap(a, b);
    anc[b] = a;
    sz[a] += sz[b];
}

signed main() { WA();
    int t; for (cin >> t; t--;) {
        int n, szlen = -1; cin >> n;
        anc.clear(); sz.clear();
        map<string, int> mp;
        while (n--) {
            string a, b; cin >> a >> b;
            if (mp.find(a) == mp.end()) {
                mp[a] = ++szlen;
                anc.pb(szlen); sz.pb(1);
            }
            if (mp.find(b) == mp.end()) {
                mp[b] = ++szlen;
                anc.pb(szlen); sz.pb(1);
            }
            Union(mp[a], mp[b]);
            cout << sz[Find(mp[a])] << '\n';
        }
    }
}