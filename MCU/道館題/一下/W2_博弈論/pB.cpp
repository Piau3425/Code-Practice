#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int t; cin >> t;
    while (t--) {
        int n, i, sum = 0; cin >> n;
        vector<int> v(2*n);
        vector<PII> coord;
        for (auto &i : v) cin >> i;
        sort(all(v));
        for (int i = 0; i < v.size()/2; i++) coord.emplace_back(v[i], v[n+i]);
        for (int i = 0; i < coord.size()-1; i++) sum += abs(coord[i].fi - coord[i+1].fi) + abs(coord[i].se - coord[i+1].se);
        cout << sum << '\n';
        for (auto i : coord) cout << i.fi << ' ' << i.se << '\n';
    }
}