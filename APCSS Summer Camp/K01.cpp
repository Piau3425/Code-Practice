#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> v(n+1);
    while (m--) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (auto &i : v) sort(i.begin(), i.end());
    for (cin >> m; m; m--) {
        cin >> a;
        for (auto i : v[a]) cout << i << ' ';
        cout << '\n';
    }
}