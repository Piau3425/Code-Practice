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

int n; // n 為節點數

struct Node {
    int data, tag;
    Node() : data(0), tag(0) {}
};

vector<Node> seg;

int get_val(int l, int r, int id) {
    return seg[id].data + seg[id].tag * (r-l+1);
}

void pull(int l, int r, int id) {
    int m = (l+r)>>1;
    seg[id].data = get_val(l, m, id<<1) + get_val(m+1, r, id<<1|1);
}

void push(int l, int r, int id) {
    if (seg[id].tag) {
        seg[id].data += seg[id].tag * (r-l+1);
        seg[id<<1].tag += seg[id].tag;
        seg[id<<1|1].tag += seg[id].tag;
        seg[id].tag = 0;
    }
}

void build(vector<int> &v, int l = 0, int r = n-1, int id = 1) {
    if (l == r) return void(seg[id].data = v[l]);
    int m = (l+r)>>1;
    build(v, l, m, id<<1);
    build(v, m+1, r, id<<1|1);
    seg[id].data = seg[id<<1].data + seg[id<<1|1].data;
}

void update(int ql, int qr, int v, int l = 0, int r = n-1, int id = 1) {
    if (l > qr || r < ql) return;
    if (l >= ql && r <= qr) return void(seg[id].tag += v);
    push(l, r, id);
    int m = (l+r)>>1;
    update(ql, qr, v, l, m, id<<1);
    update(ql, qr, v, m+1, r, id<<1|1);
    pull(l, r, id);
}

int query(int ql, int qr, int l = 0, int r = n-1, int id = 1) {
    if (l > qr || r < ql) return 0;
    if (l >= ql && r <= qr) return get_val(l, r, id);
    push(l, r, id);
    int m = (l+r)>>1;
    return query(ql, qr, l, m, id<<1) + query(ql, qr, m+1, r, id<<1|1); 
}

signed main() {
    cin >> n;
    vector<int> v(n);
    seg.assign(n<<2|1, Node());
    for (auto &i : v) cin >> i;
    build(v);
    cout << query(0, 3) << '\n';
    update(1, 3, 5);
    cout << query(0, 3) << '\n';
}