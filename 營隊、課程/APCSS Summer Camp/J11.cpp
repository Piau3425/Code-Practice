#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, mx = -1e9, t, sum = 0;

    for (cin >> n; n; n--) {
        cin >> t;
        mx = max(mx, t);
        sum += t;
    }

    cout << (mx > sum-mx ? mx*2 : sum);
}