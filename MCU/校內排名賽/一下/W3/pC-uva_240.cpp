#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define all(x) (x).begin(), (x).end()
#define EMPTY (n-1) % (r-1)

signed main() { WA();
    int r, n, t = 0;
    while (cin >> r, r) {
        cin >> n;
        vector<pair<char, int>> v(n);
        for (int i = 0; i < n; i++) cin >> v[i].se, v[i].fi = char('A' + i);
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        map<char, string> huff;
        for (int i = 0; i < n; i++) pq.push({v[i].se, string(1, char('A' + i))});
        if (EMPTY) for (int i = 0; i < r-1-EMPTY; i++) pq.push({0, "}"});
        while (pq.size() > 1) {
            int nsum = 0; string ssum;
            for (int i = 0; i < r; i++) {
                auto [f, s] = pq.top(); pq.pop();
                nsum += f;
                ssum += s;
                for (auto c : s) huff[c] = to_string(i) + huff[c];
            }
            sort(all(ssum));
            pq.push({nsum, ssum});
        }

        double w = 0, sum = 0;
        while (n--) w += huff[n+'A'].size()*v[n].se, sum += v[n].se;
        cout << "Set " << ++t << "; average length " << fixed << setprecision(2) << w/sum << '\n';
        for (auto [c, n] : v) cout << "    " << c << ": " << huff[c] << '\n';
        cout << '\n';
    }
}