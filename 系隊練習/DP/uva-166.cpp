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
    vector<int> coins = {5, 10, 20, 50, 100, 200}, cnt(6);
    double dk; //?
    while (cin >> cnt[0] >> cnt[1] >> cnt[2] >> cnt[3] >> cnt[4] >> cnt[5] >> dk, cnt[0]+cnt[1]+cnt[2]+cnt[3]+cnt[4]+cnt[5]) {
        vector<int> dp(701, INF); dp[0] = 0;
        for (int i = 0; i < 6; i++) for (int j = cnt[i]; j--;) for (int k = 700; k >= coins[i]; k--) dp[k] = min(dp[k], dp[k-coins[i]]+1);
        vector<int> sdp(701, INF); sdp[0] = 0;
        for (auto c : coins) for (int i = c; i <= 700; i++) sdp[i] = min(sdp[i], sdp[i-c]+1);
        int ans = 1e9;
        for (int tk = round(dk*100), i = tk; i <= 700; i++) ans = min(ans, dp[i]+sdp[i-tk]);
        cout << setw(3) << ans << '\n';
    }
}