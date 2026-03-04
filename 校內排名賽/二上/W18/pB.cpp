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

map<char, int> mp = {
    {'M', 1}, {'Y', 2}, {'C', 4},
    {'R', 3}, {'G', 6} ,{'V', 5},
    {'B', 7}
};

void solve() {
    vector<int> v(3); for (auto &i : v) cin >> i;
    int &a = v[0], &b = v[1], &c = v[2];
    string s; cin >> s;
    for (auto c : s) for (int i = 0; i < 3; i++) v[i] -= (mp[c]>>i)&1;
    if (a >= 0 && b >= 0 && c >= 0) cout << "YES " << a << ' ' << b << ' ' << c << '\n';
    else cout << "NO\n";
}

signed main() { WA();
    int t; for (cin >> t; t--;) solve();
}