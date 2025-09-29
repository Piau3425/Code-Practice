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
    int n, l; cin >> n >> l;
    vector<int> v(n);
    deque<int> dp;
    for (auto &i : v) cin >> i;
    for (int i = 0; i < n; i++) {
        int p = lower_bound(dp.begin(), dp.end(), v[i])-dp.begin();
        if (p == dp.size()) dp.pb(v[i]);
        else dp[p] = v[i];
    }
    cout << dp.size() << '\n';
    for (auto &i : dp) cout << i << ' '; 
}