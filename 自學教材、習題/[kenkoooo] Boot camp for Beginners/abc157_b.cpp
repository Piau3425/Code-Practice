#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    vector<vector<int>> v(3, vector<int>(3));
    map<int, bool> mp;
    for (auto &i : v) for (auto &j : i) cin >> j, mp[j] = false;
    int n; cin >> n;
    while (n--) {
        int t; cin >> t;
        mp[t] = true;
    }

    bool ans = false;
    for (int i = 0; i < 3; i++) {
        bool ck = 1;
        for (int j = 0; j < 3; j++) if (!mp[v[i][j]]) ck = 0;
        if (ck) ans = true;
    }
    for (int i = 0; i < 3; i++) {
        bool ck = 1;
        for (int j = 0; j < 3; j++) if (!mp[v[j][i]]) ck = 0;
        if (ck) ans = true;
    }
    if ((mp[v[0][0]] && mp[v[1][1]] && mp[v[2][2]]) || (mp[v[0][2]] && mp[v[1][1]] && mp[v[2][0]])) ans = true;
    if (ans) cout << "Yes";
    else cout << "No";
}