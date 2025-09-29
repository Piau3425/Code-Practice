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
inline Node *_copy(Node *x);

struct Node {
    int val, sum, pri, siz, rev;
    Node *l, *r;

    Node(int x): val(x), sum(x), pri(gen()), siz(1), rev(0), l(nullptr), r(nullptr) {}

    void pull() {
        siz = _getSiz(l) + _getSiz(r) + 1;
        sum = _getSum(l) + _getSum(r) + val;
    }
    
    void push() {
        if (rev) {
            if (l) l = _copy(l);
            if (r) r = _copy(r);
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

inline int _getSum(Node *x) {
    return (x ? x->sum : 0);
}

inline Node *_copy(Node *x) {
    Node *y = new Node(x->val);
    y->pri = x->pri;
    y->sum = x->sum;
    y->siz = x->siz;
    y->rev = x->rev;
    y->l = x->l;
    y->r = x->r;
    return y;
}

pair<Node *, Node *> _split(Node *x, int sz) {
    if (!x) return {nullptr, nullptr};
    x = _copy(x);
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
        a = _copy(a);
        a->push();
        a->r = _merge(a->r, b);
        a->pull();
        return a;
    }
    b = _copy(b);
    b->push();
    b->l = _merge(a, b->l);
    b->pull();
    return b;
}

pair<int, Node*> _query(Node *x, int l, int r) {
    x = _copy(x);
    auto [a, b] = _split(x, l-1);
    auto [ba, bb] = _split(b, r-l+1);
    int ret;
    if (ba) ret = ba->sum;
    x = _merge(a, _merge(ba, bb));
    return {ret, x};
}

Node *_seg_rev(Node *x, int l, int r) {
    x = _copy(x);
    auto [a, b] = _split(x, l-1);
    auto [ba, bb] = _split(b, r-l+1);
    ba = _copy(ba);
    ba->rev ^= 1;
    return _merge(a, _merge(ba, bb));
}

signed main() { WA();
    int n, las = 0; cin >> n;
    vector<Node *> root(n+1, nullptr);
    
    for (int i = 1; i <= n; i++) {
        int v, opt, p, x, l ,r;
        cin >> v >> opt;
        if (opt == 1) {
            cin >> p >> x;
            p ^= las, x ^= las;
            auto [a, b] = _split(root[v], p);
            Node *k = new Node(x);
            root[i] = _merge(a, _merge(k, b));
        }
        else if (opt == 2) {
            cin >> p; p^= las;
            auto [a, b] = _split(root[v], p-1);
            auto [ba, bb] = _split(b, 1);
            root[i] = _merge(a, bb);
        }
        else if (opt == 3) {
            cin >> l >> r;
            l ^= las, r ^= las;
            root[i] = _seg_rev(root[v], l, r);
        }
        else {
            cin >> l >> r;
            l ^= las, r ^= las;
            auto ret = _query(root[v], l, r);
            cout << (las = ret.first) << '\n';
            root[i] = ret.second;
        }
    }
}