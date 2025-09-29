#include <bits/stdc++.h>
using namespace std;

int main() { ios::sync_with_stdio(0); cin.tie(0);
    int n, q, pfSum = 0, l, r;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] ^= pfSum;
        pfSum = v[i];
    }

    cin >> q;
    while (q--) {
        cin >> l >> r;
        cout << (v[r] ^ v[l-1]) << '\n';
    }
}