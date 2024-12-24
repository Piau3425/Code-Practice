#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, m, prefix = 0;
    cin >> n >> m;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        prefix += tmp;
        v[i] = prefix;
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << v[b] - v[a-1] << '\n';
    }
}