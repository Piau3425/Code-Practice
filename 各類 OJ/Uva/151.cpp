#include <bits/stdc++.h>
using namespace std;

#define WA() cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main() { WA();
    int n;
    while (cin >> n, n) {
        for (int i = 1; i < n; i++) {
            int k = 0;
            for (int j = 1; j < n; j++) k = (k + i) % j;
            if (k == 11) {
                cout << i << '\n';
                break;
            }
        }
    }
}