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
    for (auto &[a, b, c] : v) cin >> a >> b >> c;

    for (int i = 1; i < n; i++) {
        auto [pa, pb, pc] = v[i-1];
        auto &[na, nb, nc] = v[i];
        na += max(pb, pc);
        nb += max(pa, pc);
        nc += max(pa, pb);
    }
    
    auto [a, b, c] = v[n-1];
    cout << max({a, b, c});
}