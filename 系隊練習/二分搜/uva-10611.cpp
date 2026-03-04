#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    for (int n, m; cin >> n;) {
        vector<int> a(n);
        for (auto &i : a) cin >> i;
        cin >> m;
        vector<int> b(m);
        for (auto &i : b) cin >> i;
        for (auto &i : b) {
            auto l = lower_bound(all(a), i), u = upper_bound(all(a), i);
            l == a.begin() && cout << 'X' << ' ' || cout << l[-1] << ' ';
            u == a.end() && cout << 'X' << '\n' || cout << *u << '\n';
        }
    }
}