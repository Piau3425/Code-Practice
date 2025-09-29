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

mt19937 gen(time(0));

struct Node;
inline int _getSiz(Node *x);
inline int _getSum(Node *x);

struct Node {
    int val, pri, siz, rev;
    Node *l, *r;

    Node(int x): val(x), pri(gen()), siz(1), rev(0), l(nullptr), r(nullptr) {}

    inline void pull() {
        siz = _getSiz(l) + _getSiz(r) + 1;
    }
    
    inline void push() {
        if (rev) {
            swap(l, r);
            if (l) l->rev ^= 1;
            if (r) r->rev ^= 1;
            rev = 0;
        }
    }
};

inline int _getSiz(Node *x) {
    return (x ? x->siz : 0);
}

pair<Node *, Node *> _split(Node *x, int sz) {
    if (!x) return {nullptr, nullptr};
    x->push();
    if (sz <= _getSiz(x->l)) {
        auto [a, b] = _split(x->l, sz);
        x->l = b;
        x->pull();
        return {a, x};
    }
    else {
        auto [a, b] = _split(x->r, sz - _getSiz(x->l) - 1);
        x->r = a;
        x->pull();
        return {x, b};
    }
}

Node *_merge(Node *a, Node *b) {
    if (!a) return b;
    if (!b) return a;

    a->push(); b->push();
    if (a->pri < b->pri) {
        a->r = _merge(a->r, b);
        a->pull();
        return a;
    }
    else {
        b->l = _merge(a, b->l);
        b->pull();
        return b;
    }
}

Node *_build_rec(vector<int> &v, int l, int r) {
    if (l > r) return nullptr;
    int mid = (l+r) / 2;
    Node *x = new Node(v[mid]);
    x->l = _build_rec(v, l, mid-1);
    x->r = _build_rec(v, mid+1, r);
    x->pull();
    return x;
}

void _traversal(Node *x) {
    if(!x) return;
    x->push();
    if (x->l) _traversal(x->l);
    cout << x->val << ' ';
    if (x->r) _traversal(x->r);
}

void _seg_rev(Node *&x, int l, int r) {
    auto [a, b] = _split(x, l);
    auto [ba, bb] = _split(b, r-l+1);
    if (ba) ba->rev ^= 1;
    x = _merge(a, _merge(ba, bb));
}

signed main() { WA();
    int n, q; cin >> n >> q;
    vector<int> v(n);
    iota(all(v), 1);
    Node *root;
    root = _build_rec(v, 0, n-1);
    while (q--) {
        int l, r; cin >> l >> r;
        l--, r--;
        _seg_rev(root, l, r);
    }

    _traversal(root);
}