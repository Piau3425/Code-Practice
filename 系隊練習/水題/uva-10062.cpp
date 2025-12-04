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
    string s;
    int t = 0;
    while (getline(cin, s)) {
        if (t++) cout << '\n';
        map<int, int> mp;
        for (auto c : s) mp[c]++;
        vector<PII> v;
        for (auto i : mp) v.pb({i.se, -i.fi});
        sort(all(v));
        for (auto i : v) cout << -i.se << ' ' << i.fi << '\n';
    }
}