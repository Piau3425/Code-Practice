#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>
#define lc now*2
#define rc now*2+1

vector<int> v;
vector<int> tree;

void build(int l, int r, int now) {
    if (l == r) return void(tree[now] = v[l]);
    int m = (l+r) / 2;
    build(l, m, lc), build(m+1, r, rc);
    tree[now] = min(tree[lc], tree[rc]);
}

void upd(int idx, int ql, int qr, int now, int k) {
    if (ql == qr) return void(tree[now] = k);

    int m = (ql+qr) / 2;
    if (idx <= m) upd(idx, ql, m, lc, k);
    else upd(idx, m+1, qr, rc, k);
    tree[now] = min(tree[lc], tree[rc]);
}

int query(int l, int r, int ql, int qr, int now) {
    if (l <= ql && qr <= r) return tree[now];

    int m = (ql+qr) / 2, sum = 0, mnL, mnR; mnL = mnR = 1e9;
    if (l <= m) mnL = query(l, r, ql, m, lc);
    if (r >= m+1) mnR = query(l, r, m+1, qr, rc);
    return min(mnL, mnR);
}

signed main() { WA();
    int n, q; cin >> n >> q;
    v.resize(n+1);
    tree.resize(4*n);
    for (int i = 1; i <= n; i++) cin >> v[i];
    build(1, n, 1);
    while (q--) {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if (cmd == 1) upd(a, 1, n, 1, b);
        else cout << query(a, b, 1, n, 1) << '\n';
    }
}