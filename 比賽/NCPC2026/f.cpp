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
#define TIII tuple<int, int, int>

int dp[305][305];

signed main() { WA();
    int n, t, k; cin >> n >> t >> k;
    vector<PII> v(n);
    for (auto &i : v) cin >> i.fi >> i.se, i.fi *= 2;

    for (auto &[time, egg] : v) {
        for (int i = t; i >= time; i--) {
            for (int j = k; j >= egg; j--) {
                dp[i][j] = max(dp[i][j], dp[i-time][j-egg]+1);
            }
        }
    }
    
    cout << dp[t][k] << '\n';
}