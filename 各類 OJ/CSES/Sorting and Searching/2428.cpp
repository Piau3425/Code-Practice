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
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    unordered_map<int, int> mp;
    int ans = 0;
    for (int l = 0, r = 0; r < n; r++) {
        mp[v[r]]++;
        while (l <= r && mp.size() > k) {
            if (!--mp[v[l]]) mp.erase(v[l]);
            l++;
        }
        if (mp.size() <= k) ans += r-l+1;
    }
    cout << ans;
}