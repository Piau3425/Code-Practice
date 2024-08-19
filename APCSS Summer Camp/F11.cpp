#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, sum = 0;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;

    for (int i = 1; i < n; i++) if (v[i] < v[i-1]) {
        sum += abs(v[i] - v[i-1]);
        v[i] = v[i-1];
    }
    cout << sum;
}