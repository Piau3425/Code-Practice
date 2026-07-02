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

void solve(int n, int m, vector<string> &v) {
    string s; cin >> s;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) 
    for (int mx = -1; mx <= 1; mx++) for (int my = -1; my <= 1; my++) if (mx || my) {
        int x = i, y = j, k = 0;
        for (; k < s.size() && x >= 0 && x < n && y >= 0 && y < m; k++, x += mx, y += my) if (tolower(v[x][y]) != tolower(s[k])) break;
        if (k == s.size()) return cout << i+1 << ' ' << j+1 << '\n', void();
    }
}

signed main() { WA();
    int t; for (cin >> t; t--;) {
        int n, m; cin >> n >> m;
        vector<string> v(n);
        for (auto &i : v) cin >> i;
        int q; for (cin >> q; q--;) solve(n, m, v);
        if (t) cout << '\n';
    }
}