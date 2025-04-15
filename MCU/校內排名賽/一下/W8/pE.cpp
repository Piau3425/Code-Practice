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

signed main() { WA();
    int r, n, t = 0;
    while (cin >> n, n) {
        //if (t++) cout << '\n';
        vector<pair<double, set<int>>> v(n), g; // 索引值 = 機率 : 霍夫曼編碼
        for (int i = 0; i < n; i++) {
            cin >> v[i].fi;
            v[i].se = set<int>{i};
        }
        g = v;

        map<int, string> huff;
        while (v.size() > 1) {
            double a, b, mn = 1e9;
            for (int i = 0; i+1 < v.size(); i++) if (v[i].fi+v[i+1].fi < mn) mn = v[i].fi+v[i+1].fi, a = i, b = i+1;
            for (auto c : v[a].se) huff[c] = '0' + huff[c];
            for (auto c : v[b].se) huff[c] = '1' + huff[c];
            v[a].fi += v[b].fi;
            for (auto i : v[b].se) v[a].se.insert(i);
            v.erase(v.begin()+b);
        }

        double sum = 0;
        for (auto i : huff) sum += g[i.fi].fi*(int)i.se.size();
        cout << fixed << setprecision(4) << sum << '\n';
        for (auto i : huff) cout << i.se << '\n';        
    }
}