#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() { ios::sync_with_stdio(0); cin.tie(0);
    int n, x, pfSum = 0, ans = 0, input;
    cin >> n >> x;
    map<int, int> mp;
    mp[0] = 1;
    while (n--) {
        cin >> input;
        pfSum += input;
        ans += mp[pfSum - x];
        mp[pfSum]++;
    }
    cout << ans;
}