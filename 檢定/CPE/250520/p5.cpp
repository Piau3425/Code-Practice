#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    vector<int> dp(30005, 1), a = {5, 10, 25, 50};
    for (auto &c : a) for (int i = c; i < 30005; i++) dp[i] += dp[i-c];
    while (cin >> n) {
        if (dp[n] == 1) cout << "There is only 1 way to produce " << n << " cents change.\n";
        else cout << "There are " << dp[n] << " ways to produce " << n << " cents change.\n";
    }
}