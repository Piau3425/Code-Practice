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
    int r, c;
    while (cin >> r >> c) {
        cin.ignore();
        vector<vector<string>> v(r);
        for (int i = 0; i < r; i++) {
            string s;
            getline(cin, s);
            stringstream ss(s);
            while (getline(ss, s, ',')) v[i].pb(s);
        }

        bool ck = 1;
        for (int j = 0; j < c && ck; j++) for (int k = j+1; k < c && ck; k++) {
            unordered_map<string, PII> mp;
            for (int i = 0; i < r; i++) {
                if (mp.find(v[i][j]+char(127)+v[i][k]) == mp.end()) mp[v[i][j]+char(127)+v[i][k]] = {i, j};
                else {
                    cout << "NO\n" << mp[v[i][j]+char(127)+v[i][k]].fi+1 << ' ' << i+1 << '\n' << mp[v[i][j]+char(127)+v[i][k]].se+1 << ' ' << k+1 << '\n';
                    ck = 0;
                    break;
                }
            }
        }
        ck && (cout << "YES\n");
    }
}