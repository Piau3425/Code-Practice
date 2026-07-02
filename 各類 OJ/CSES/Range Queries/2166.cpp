#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>
#define lc (p<<1)
#define rc (p<<1|1)

template<typename T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define MAXN 200005

struct Node {
    int sum, mp;
};

Node seg[MAXN << 2];
int arr[MAXN+1];

void pu(int p, int l, int r) {
    seg[p].sum = seg[lc].sum + seg[rc].sum;
}

void pd(int p, int l, int r) {

}

void build(int p, int l, int r) {
    if (l == r) return seg[p].sum = arr[l], void();
    
    int mid = (l+r)>>1;
    build(lc, l, mid);
    build(rc, mid+1, r);
    pu(p, l, r);
}

int query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return seg[p].mp;

    pd(p, l, r);
    int mid = (l+r)>>1, ret = 0;
    if (l <= ql) 
}

signed main() { WA();
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, 1);


}