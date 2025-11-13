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
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    vector<int> g;
    for (auto &i : v) {
        if (auto it = upper_bound(all(g), i); it != g.end()) *it = i;
        else g.pb(i);
    }
    cout << g.size() << '\n';
}