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
    int n; cin >> n; cin.ignore();
    string s;
    getline(cin, s);
    while (n--) {
        map<string, int> mp;
        int cnt = 0;
        while (getline(cin, s), s != "") {
            mp[s]++;
            cnt++;
        }
        for (auto &i : mp) cout << i.fi << ' ' << fixed << setprecision(4) << (double)i.se/cnt*100 << '\n';;
        if (n) cout << '\n';
    }
}