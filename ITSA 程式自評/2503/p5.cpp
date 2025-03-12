#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

map<string, string> anc;

string Find(string x) {
    return (anc[x] == x ? x : anc[x] = Find(anc[x]));
}

bool Union(string a, string b) {
    a = Find(a), b = Find(b);
    if (a == b) return false;
    return anc[b] = a, true;
}

signed main() { WA();
    int n, m;
    cin >> n >> m;
    vector<string> name(n);
    map<string, vector<string>> link;
    vector<tuple<int, string, string>> g;
    for (auto &i : name) {
        cin >> i;
        anc[i] = i;
    }

    while (m--) {
        string a, b;
        int w;
        cin >> a >> b >> w;
        g.pb({w, a, b});
    }
    
    sort(all(g));
    int ans = 0;
    for (auto [w, a, b] : g) if (Union(a, b)) {
        link[a].pb(b);
        ans += w;
    }
    for (auto i : name) if (link[i].size()) {
        sort(all(link[i]));
        for (auto j : link[i]) cout << "(" << i << " " << j<< ")";
    }
    cout << '\n' << ans << '\n';
}