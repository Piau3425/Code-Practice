#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() { ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> shop(n+1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        shop[b].push_back(a);
    }
    while (q--) {
        int ask;
        cin >> ask;
        if (shop[ask].size()) for (int i = 0; i < shop[ask].size(); i++) cout << (i ? " " : "") << shop[ask][i];
        cout << '\n';
    }
}