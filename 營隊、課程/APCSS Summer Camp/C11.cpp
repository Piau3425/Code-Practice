#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> v(n, vector<int>(n));
    for (auto &a : v) for (auto &b : a) cin >> b;

    while (q--) {
        int k, sum = 0;
        cin >> k;
        vector<int> kid(k);
        for (auto &i : kid) cin >> i;
        for (int i = 0; i < k; i++) {
            for (int j = i+1; j < k; j++) sum += v[kid[i]-1][kid[j]-1] + v[kid[j]-1][kid[i]-1];
        }
        cout << sum << '\n';
    }
}