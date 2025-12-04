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
        int k; cin >> k;
        map<string, bool> mp;
        vector<string> v(k);
        bool ck = true;
        for (auto &i : v) cin >> i;
        sort(all(v));
        for (auto s : v) {
            string tmp;
            for (auto c : s) {
                tmp += c;
                if (mp.find(tmp) != mp.end()) ck = false;
            }
            mp[s] = true;
        }
        cout << (ck ? "YES" : "NO") << '\n';
    }
}