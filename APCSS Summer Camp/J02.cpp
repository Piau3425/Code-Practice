#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, ans = -1e9, v, sum = 0;
    cin >> n;
    
    while (n--) {
        cin >> v;
        ans = max(sum += v, ans);
        sum = max(sum, 0LL);
    }

    cout << ans;
}