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
    int n, m; cin >> n >> m;
    anc.assign(n, 0);
    iota(all(anc), 0);
    while (m--) {
        int a, b; cin >> a >> b;
        a--, b--;
        Union(a, b);
    }
    set<int> st;
    for (auto &i : anc) st.insert(Find(i));
    vector<int> ans; for (auto &i : st) ans.pb(i);
    cout << st.size()-1 << '\n';
    for (int i = 0; i+1 < ans.size(); i++) cout << ans[i]+1 << ' ' << ans[i+1]+1 << '\n';
}