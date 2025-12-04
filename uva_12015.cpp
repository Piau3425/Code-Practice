#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n; cin >> n;
    for (int i = 1; i <= n; i++) { cout << "Case #" << i << ":\n";
        set<pair<PII, string>> st;
        string s; int m;
        for (int i = 0; i < 10; i++) cin >> s >> m, st.insert({{m, i}, s});
        m = max_element(all(st))->first.fi;
        for (auto i : st) if (i.fi.fi == m) cout << i.se << '\n';
    }
}