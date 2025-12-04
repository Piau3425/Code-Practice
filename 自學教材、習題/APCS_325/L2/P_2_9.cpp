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

int p;

void rec(vector<int> &v, map<int, int> &mp, int idx, int prod) {
    if (idx == v.size()) return void(mp[prod]++);

    rec(v, mp, idx+1, prod*v[idx]%p);
    rec(v, mp, idx+1, prod);
}

void ext_euc(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return;
    }
    ext_euc(b, a%b, y, x);
    y -= a/b*x;
}

signed main() { WA();
    int n; cin >> n >> p;
    vector<int> a(n/2), b(n/2+(n&1));
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    map<int, int> ma, mb;
    rec(a, ma, 0, 1);
    rec(b, mb, 0, 1);
    ma[1]--; mb[1]--;
    int ans = (ma[1]+mb[1])%p;
    for (auto &i : ma) {
        int x, y;
        ext_euc(i.fi, p, x, y);
        auto it = mb.find((x+p)%p);
        if (it != mb.end()) ans = (ans+i.se*it->se)%p;
    }
    cout << ans << '\n';
}