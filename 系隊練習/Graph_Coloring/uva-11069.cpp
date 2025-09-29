#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long

signed main() { WA();
    vector<int> dp(77);
    dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 2;
    for (int i = 4; i < 77; i++) dp[i] = dp[i-2] + dp[i-3];
    int n;
    while (cin >> n) cout << dp[n] << '\n';
}