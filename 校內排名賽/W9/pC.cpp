#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define WA() cin.tie(0)->sync_with_stdio(0)
#define int long long
#define all(x) (x).begin(), (x).end()
#define EMPTY (n-1) % (r-1)
#define PIS pair<int, string>

signed main() { WA();
    int r, n, t = 0;
    while (cin >> r, r) {
        cin >> n;
        vector<pair<char, int>> v(n);
        for (int i = 0; i < n; i++) cin >> v[i].se, v[i].fi = char('A' + i);
        map<char, string> huf;
        priority_queue<PIS, vector<PIS>, greater<PIS>> pq;
        for (int i = 0; i < n; i++) {
            string s = "A"; s[0] += i; 
            pq.push({v[i].se, s});
        }
        if (EMPTY) for (int i = 0; i < r-1-EMPTY; i++) pq.push({0, "}"});
        while (pq.size() > 1) {
            int nsum = 0; string strsum;
            for (int i = 0; i < r; i++) {
                nsum += pq.top().fi;
                strsum += pq.top().se;
                for (auto c : pq.top().se) huf[c] = to_string(i) + huf[c];
                pq.pop();
            }
            sort(all(strsum));
            pq.push({nsum, strsum});
        }

        double w = 0, sum = 0;
        while (n--) w += huf[n+'A'].size()*v[n].se, sum += v[n].se;
        cout << "Set " << ++t << "; average length " << fixed << setprecision(2) << w/sum << '\n';
        for (auto i : v) cout << "    " << i.fi << ": " << huf[i.fi] << '\n';
        cout << '\n';
    }
}