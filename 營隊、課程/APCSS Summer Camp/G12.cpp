#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, l, r;
    cin >> n;
    map<int, int> mp; // 溫度，差分
    while (n--) {
        cin >> l >> r;
        mp[l]++;
        mp[r] += 0;
        mp[r+1]--;
    }
    
    int prefix = 0;
    for (auto &i : mp) { // 差分 換成 前綴和
        prefix += i.second;
        i.second = prefix;
    }

    int ans, mx = -1e9;
    for (auto i : mp) {
        if (i.second >= mx) {
            mx = i.second;
            ans = i.first;
        }
    }

    cout << ans;
}