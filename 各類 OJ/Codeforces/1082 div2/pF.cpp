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

int n, q;
vector<int> a;
vector<set<int>> pos;

struct Node {
    int mx, len, pref, suff, ans;
    Node(int val = -1) : mx(val), len(1) {
        if (~val) pref = suff = ans = 1;
        else pref = suff = ans = 0;
    }
};

vector<Node> seg;

inline Node pull(Node a, Node b) {
    Node res;
    res.len = a.len + b.len;
    if (a.mx == b.mx) {
        res.mx = a.mx;
        res.ans = a.ans + b.ans;
        if (~a.mx && a.suff && b.pref) {
            res.ans -= a.suff * (a.suff + 1) / 2 + b.pref * (b.pref + 1) / 2;
            res.ans += (a.suff + b.pref) * (a.suff + b.pref + 1) / 2;
        }
        res.pref = a.pref + (a.pref == a.len ? b.pref : 0);
        res.suff = b.suff + (b.suff == b.len ? a.suff : 0);
    } else if (a.mx > b.mx) {
        res.mx = a.mx;
        res.ans = a.ans;
        res.pref = a.pref;
        res.suff = 0;
    } else {
        res.mx = b.mx;
        res.ans = b.ans;
        res.pref = 0;
        res.suff = b.suff;
    }
    return res;
}

void build(int l = 1, int r = n, int id = 1) {
    if (l == r) return void(seg[id] = Node(-1));
    int m = (l + r) >> 1;
    build(l, m, id << 1);
    build(m + 1, r, id << 1 | 1);
    seg[id] = pull(seg[id << 1], seg[id << 1 | 1]);
}

void update(int p, int v, int l = 1, int r = n, int id = 1) {
    if (l == r) return void(seg[id] = Node(v));
    int m = (l + r) >> 1;
    if (p <= m) update(p, v, l, m, id << 1);
    else update(p, v, m + 1, r, id << 1 | 1);
    seg[id] = pull(seg[id << 1], seg[id << 1 | 1]);
}

inline void add(int x, int i) {
    if (pos[x].size()) update(*pos[x].begin(), -1);
    pos[x].insert(i);
    update(*pos[x].begin(), *pos[x].rbegin() - *pos[x].begin());
}

inline void del(int x, int i) {
    update(*pos[x].begin(), -1);
    pos[x].erase(i);
    if (pos[x].size()) update(*pos[x].begin(), *pos[x].rbegin() - *pos[x].begin());
}

void solve() {
    cin >> n >> q;
    a.assign(n + 1, 0);
    pos.assign(n + 1, set<int>());
    seg.assign(n << 2 | 1, Node());
    build();
    
    for (int i = 1; i <= n; i++) cin >> a[i], add(a[i], i);
    
    while (q--) {
        int i, x; cin >> i >> x;
        if (a[i] != x) del(a[i], i), add(x, i), a[i] = x;
        
        if (!seg[1].mx) cout << "0 0\n"; else cout << seg[1].mx << " " << seg[1].ans << "\n";
    }
}

signed main() { WA();
    int t;
    for (cin >> t; t--;) solve();
}