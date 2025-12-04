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
    int n; cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    set<int> all;
    for (auto &i : v) all.insert(i);
    map<int, int>  mp;
    int ans = 1e9, now = 0;
    for (int l = 0, r = 0; r < n; r++) {
        if(++mp[v[r]] == 1) now++;
        while (mp[v[l]] > 1) {
            mp[v[l]]--;
            l++;
        }
        if (now == all.size()) ans = min(ans, r-l+1);
    }
    cout << ans;
}