#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, time = 0, ans = 0;
    vector<pair<int, int>> v;
    cin >> n;

    while (n--) {
        int a, d;
        cin >> a >> d;
        v.emplace_back(a, d);
    }

    sort(v.begin(), v.end());
    for (auto i : v) ans += i.second - (time += i.first);
    cout << ans;
    
}