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

void upd(int x, int v, vector<int> &bit) {
    for (int i = x; i < bit.size(); i += i&-i) bit[i] += v;
}

int query(int x, vector<int> &bit) {
    int ret = 0;
    for (int i = x; i; i -= i&-i) ret += bit[i];
    return ret;
} 

signed main() { WA();
    int n, q; cin >> n >> q;
    vector<int> v(n), bit(n+1);
    for (auto &i : v) cin >> i;
    upd(1, v[0], bit);
    for (int i = 1; i < n; i++) upd(i+1, v[i]-v[i-1], bit);
    while (q--) {
        int c, a, b, u;
        cin >> c;
        if (c == 1) {
            cin >> a >> b >> u;
            upd(a, u, bit);
            upd(b+1, -u, bit);
        }
        else cin >> u, cout << query(u, bit) << '\n';
    }
}