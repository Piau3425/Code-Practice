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
inline int _getMax(Node *x);

struct Node {
    int val, pri, siz, _add, rev, mx;
    Node *l, *r;

    Node(int x): val(x), pri(gen()), siz(1), _add(0), rev(0), mx(x), l(nullptr), r(nullptr) {}

    void pull() {
        siz = _getSiz(l) + _getSiz(r) + 1;
        mx = max({_getMax(l), _getMax(r), val});
    }

    void add(int k) {
        _add += k;
        val += k;
        mx += k;
    }
    
    void push() {
        if (rev) {
            swap(l, r);
            if (l) l->rev ^= 1;
            if (r) r->rev ^= 1;
            rev = 0;
        }
        if (_add) {
            if (l) l->add(_add);
            if (r) r->add(_add);
            _add = 0;
        }
    }
};

inline int _getSiz(Node *x) {
    return (x ? x->siz : 0);
}

inline int _getMax(Node *x) {
    return (x ? x->mx : -INF);
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
    auto [a, b] = _split(x->r, sz - _getSiz(x->l) - 1);
    x->r = a;
    x->pull();
    return {x, b};
}

Node *_merge(Node *a, Node *b) {
    if (!a) return b;
    if (!b) return a;

    if (a->pri < b->pri) {
        a->push();
        a->r = _merge(a->r, b);
        a->pull();
        return a;
    }
    b->push();
    b->l = _merge(a, b->l);
    b->pull();
    return b;
}

void _seg_rev(Node *&x, int l, int r) {
    auto [a, b] = _split(x, l-1);
    auto [ba, bb] = _split(b, r-l+1);
    if (ba) ba->rev ^= 1;
    x = _merge(a, _merge(ba, bb));
}

void _seg_add(Node *&x, int l, int r, int val) {
    auto [a, b] = _split(x, l-1);
    auto [ba, bb] = _split(b, r-l+1);
    if (ba) ba->add(val);
    x = _merge(a, _merge(ba, bb));
}

signed main() { WA();
    int n, m; cin >> n >> m;
    Node *root = nullptr;
    for (int i = 0; i < n; i++) root = _merge(root, new Node(0));
    while (m--) {
        int k, l, r, v;
        cin >> k >> l >> r;
        if (k == 1) {
            cin >> v;
            _seg_add(root, l, r, v);
        }
        else if (k == 2) _seg_rev(root, l, r);
        else {
            auto [a, b] = _split(root, l-1);
            auto [ba, bb] = _split(b, r-l+1);
            cout << ba->mx << '\n';
            root = _merge(a, _merge(ba, bb));
        }
    }
}