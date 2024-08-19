#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, mx = -1e9;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;

    for (int i = 0; i < v.size(); i++) {
        for (int j = i+1; j < v.size(); j++) mx = max(mx, v[i]-v[j]);
    }
    cout << mx;
}