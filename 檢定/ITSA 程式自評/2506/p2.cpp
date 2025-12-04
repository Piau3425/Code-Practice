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
    int n, t; cin >> n >> t;
    map<int, int> mp;
    while (n--) {
        int k; cin >> k;
        mp[k]++;
    }
    for (auto &i : mp) if (i.se >= t) cout << i.fi << "," << i.se << '\n';
}