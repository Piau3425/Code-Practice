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
    int t; cin >> t;
    while (t--) {
        int r, c; cin >> r >> c;
        string ans; int err = 0;
        vector<vector<char>> v(r, vector<char>(c));
        for (auto &i : v) for (auto &j : i) cin >> j;
        for (int i = 0; i < c; i++) {
            vector<int> cnt(26);
            for (int j = 0; j < r; j++) cnt[v[j][i] - 'A']++;
            ans += max_element(all(cnt))-cnt.begin() + 'A';
            err += r - *max_element(all(cnt));
        }

        cout << ans << '\n' << err << '\n';
    }
}