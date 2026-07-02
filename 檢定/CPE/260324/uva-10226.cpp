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
    int t; for (cin >> t, cin.ignore(), cin.ignore(); t--;) {
        string s;
        map<string, int> mp;
        int cnt = 0;
        while (getline(cin, s), s.size()) mp[s]++, cnt++;
        for (auto [tree, num] : mp) cout << tree << ' ' << fixed << setprecision(4) << (double)100*num/cnt << '\n';
        if (t) cout << '\n';
    }
}