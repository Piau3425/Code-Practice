#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() { ios::sync_with_stdio(0); cin.tie(0);
    int n, l;
    cin >> n >> l;
    set<int> s;
    vector<int> v(n);
    s.insert(0);
    s.insert(l);
    while (n--) {
        int a, b;
        cin >> a >> b;
        v[b-1] = a;
    }

    int cost = 0;
    for (auto i : v) {
        s.insert(i);
        auto it = s.lower_bound(i);
        cost += *next(it) - *prev(it);
    }
    cout << cost;
}