#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t, k = 0;
    for (cin >> t; t; t--) {
        int n, a = 0, b = 0;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        for (int i = 1; i < n; i++) {
            if (v[i]-v[i-1] > 0) a++;
            else if (v[i]-v[i-1] < 0) b++;
        }
        cout << "Case " << ++k << ": " << a << ' ' << b << '\n';
    }
}