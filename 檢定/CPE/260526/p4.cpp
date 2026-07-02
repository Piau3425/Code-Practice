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
    int t; for (cin >> t; t--;) {
        int n, k; cin >> n >> k;
        vector<pair<vector<int>, char>> v(k);
        for (auto &i : v) {
            int siz; cin >> siz;
            i.fi.resize(siz*2);
            for (auto &j : i.fi) cin >> j;
            cin >> i.se;
        }

        int coin = 0, cnt = 0;
        for (int i = 1; i <= n; i++) {
            int passL = 0, passH = 0;
            for (auto &j : v) {
                int l[2] = {}, h[2] = {};
                for (auto &k : j.fi) {
                    l[&k-j.fi.data() >= j.fi.size()/2] += (k == i ? 1 : 2);
                    h[&k-j.fi.data() >= j.fi.size()/2] += (k == i ? 2 : 1);
                }
                passL += j.se == '<' && l[0] < l[1] || j.se == '>' && l[0] > l[1] || j.se == '=' && l[0] == l[1];
                passH += j.se == '<' && h[0] < h[1] || j.se == '>' && h[0] > h[1] || j.se == '=' && h[0] == h[1];
            }
            if (passL == k || passH == k) coin = i, cnt++;
        }

        if (cnt == 1) cout << coin << '\n';
        else cout << "0\n";
        if (t) cout << '\n';
    }
}