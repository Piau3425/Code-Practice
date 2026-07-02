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
    int t, x; cin >> t >> x;
    vector<int> v(t+1);
    for (auto &i : v) cin >> i;
    int last = v[0]; cout << 0 << ' ' << last << '\n';
    for (int i = 1; i <= t; i++) if (abs(v[i]-last) >= x) cout << i << ' ' << v[i] << '\n', last = v[i];
}