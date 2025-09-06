#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, t;
    while (cin >> n >> m) {
        if (m == n-1 || (n == m && !(n&1))) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
        while (m--) cin >> t >> t;
    }
}