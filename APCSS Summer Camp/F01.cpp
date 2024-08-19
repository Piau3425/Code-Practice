#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() { ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, tmp;
    vector<int> v(1000000, 0);
    cin >> n;
    while (n--) {
        cin >> tmp;
        v[tmp]++;
    }

    cin >> q;
    while (q--) {
        cin >> tmp;
        if (tmp > 1000000) cout << "0\n";
        else cout << v[tmp] << '\n';
    }
}