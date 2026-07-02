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
#define MAXN 200005
#define lc (p<<1)
#define rc (p<<1|1)

int tree[4*MAXN];

void build(int p, int l, int r, vector<int> &v) {
    if (l == r) return tree[p] = v[l], void();

    int mid = (l+r)>>1;
    build(lc, l, mid, v);
    build(rc, mid+1, r, v);
    tree[p] = max(tree[lc], tree[rc]);
}

int qu(int p, int l, int r, int x) {
    if (tree[p] < x) return 0;
    if (l == r) {
        tree[p] -= x;
        return l;
    }

    int mid = (l+r)>>1, ret = (tree[lc] >= x ? qu(lc, l, mid, x) : qu(rc, mid+1, r, x));
    tree[p] = max(tree[lc], tree[rc]);
    return ret;
}

signed main() { WA();
    int n, m; cin >> n >> m;
    vector<int> v(n+1); for (int i = 1; i <= n; i++) cin >> v[i];
    build(1, 1, n, v);
    while (m--) {
        int x; cin >> x;
        cout << qu(1, 1, n, x) << (m ? " " : "");
    }
}