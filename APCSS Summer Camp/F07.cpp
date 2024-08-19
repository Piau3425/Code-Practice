#include <bits/stdc++.h>
using namespace std;

int main() { ios_base::sync_with_stdio(0); cin.tie(0);
    int n, p;
    cin >> n >> p;
    vector<int> v(n), a(n, 0);
    for (auto &i : v) cin >> i;

    while (p--) {
        int x, y, z;
        cin >> x >> y >> z;
        a[x-1] += z;
        a[y] -= z;
    }
    
    int mn = 1e9, cur = 0;
    for (int i = 0; i < n; i++) {
        cur += a[i];
        mn = min(v[i] + cur, mn);
    }
    cout << mn;
}