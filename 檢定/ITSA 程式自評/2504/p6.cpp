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
    for (int i = 1; i+1 < v.size(); i++) {
        vector<int> g = v;
        sort(g.begin()+i-1, g.begin()+i+2);
        v[i] = g[i];
    }
    for (auto &i : v) cout << i << " \n"[&i == &v.back()];
}