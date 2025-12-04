#include <bits/stdc++.h>
using namespace std;

#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long

signed main() { WA();
    int n;
    while (cin >> n) {
        vector<int> v(n);
        iota(v.rbegin(), v.rend(), 1);
        do {
            for (auto &i : v) cout << i;
            cout << '\n';
        } while (prev_permutation(all(v)));
    }
}