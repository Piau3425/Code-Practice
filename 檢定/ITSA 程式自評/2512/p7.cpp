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
    vector<tuple<int, int, int>> v;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w; cin >> w;
            v.pb({w, i, j});
        }
    }
    sort(all(v), greater<tuple<int, int, int>>());
    vector<int> a(n+1), b(n+1);
    for (auto &[w, aa, bb] : v) {
        if (!a[aa] && !b[bb]) {
            cout << "Company " << aa << " pair with Talent " << bb << '\n';
            a[aa] = 1;
            b[bb] = 1;
        }
    }
}