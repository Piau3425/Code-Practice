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
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    int ans = 0;
    map<int, int> mp; mp[0] = 1;
    vector<int> prefix(n+1);
    for (int i = 1; i <= n; i++) prefix[i] = v[i-1]+prefix[i-1];
    for (int i = 1; i <= n; i++) {
        ans += mp[prefix[i]-x];
        mp[prefix[i]]++;
    }
    cout << ans << '\n';
}