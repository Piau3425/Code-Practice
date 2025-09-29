#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    sort(v.begin(), v.end());

    if (n&1) cout << v[(n-1)/2];
    else cout << (v[n/2] + v[n/2-1])/2;
}