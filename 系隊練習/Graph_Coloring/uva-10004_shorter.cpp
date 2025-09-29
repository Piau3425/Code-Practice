#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> v(n);
        vector<int> co(n);
        while (m--) {
            int a, b; cin >> a >> b;
            v[a].pb(b);
            v[b].pb(a);
        }
        
        int ck = 1; co[0] = 1;
        for (int i = 0; i < n; i++) for (auto &u : v[i]) if (co[i] && co[i] == co[u]) ck = 0; else co[u] = 3-co[i];
        if(ck) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
    }
}