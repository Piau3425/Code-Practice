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
#define N 1000000+1

signed main() { WA();
    vector<int> dp(N, INF);
    for (int i = 1; i < 10; i++) dp[i] = 1;
    for (int i = 0; i < N; i++) for (auto &c : to_string(i))
    dp[i] = min(dp[i], dp[i-c+'0']+1);
    int n; cin >> n;
    cout << dp[n] << '\n';
}