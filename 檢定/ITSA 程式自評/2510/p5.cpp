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
    int n; cin >> n;
    vector<tuple<int, int, int>> v(n);
    for (auto &i : v) cin >> get<2>(i) >> get<0>(i) >> get<1>(i);
    stable_sort(all(v), greater<tuple<int, int, int>>());
    for (auto &i : v) {
        int a, b, c;
        tie(a, b, c) = i;
        cout << c << ' ' << a << ' ' << b << '\n';
    }
}