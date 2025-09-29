#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;

    int s = 0, in = 0, d = 0;
    for (int i = 0; i+1 < n; i++) {
        if (v[i] >= v[i+1]) d++;
        if (v[i] <= v[i+1]) in++;
        if (v[i] == v[i+1]) s++;
    }

    n--;
    if (s == n) cout << "SAME";
    else if (in == n) cout << "INCREASING";
    else if (d == n) cout << "DECREASING";
    else cout << "NO";
}