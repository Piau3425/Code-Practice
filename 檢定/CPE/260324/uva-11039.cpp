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

signed main() { WA();
    int t, n, x; for (cin >> t; t--;) {
        vector<vector<int>> v(2);
        for (cin >> n; n--;) {
            cin >> x;
            v[x < 0].pb(abs(x));
        }

        sort(all(v[0])); sort(all(v[1]));
        
        if (v[0].empty() || v[1].empty()) {
            cout << !v[0].empty() + !v[1].empty() << '\n';
            continue;
        }
        
        if (v[0].back() < v[1].back()) swap(v[0], v[1]);

        int idx = v[0].size() - 1, f = 0, cnt = 0;
        while (idx >= 0) {
            cnt++;
            idx = lower_bound(all(v[!f]), v[f][idx]) - v[!f].begin() - 1;
            f = !f;
        }
        cout << cnt << '\n';
    }
}