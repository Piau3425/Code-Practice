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
    int val, sum, pri, siz, _add, _set_tag, _set_val;
    Node *l, *r;

    Node(int x): val(x), sum(x), pri(gen()), siz(1), _add(0), _set_tag(0), _set_val(0), l(nullptr), r(nullptr) {}

    void pull() {
        siz = _getSiz(l) + _getSiz(r) + 1;
        sum = _getSum(l) + _getSum(r) + val;
    }

    void set(int k) {
        _set_tag = 1;
        _set_val = k;
        _add = 0;
        val = k;
        sum = siz * k;
    }

    void add(int k) {
        if (_set_tag) _set_val += k;
        else _add += k;
        val += k;
        sum += siz * k;
    }
    
    void push() {
        if (_set_tag) {
            if (l) l->set(_set_val);
            if (r) r->set(_set_val);
            _set_tag = 0;
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

inline int _getSum(Node *x) {
    return (x ? x->sum : 0);
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

void _build(Node *&x, vector<int> &v) {
    x = nullptr;
    for (int i = 0; i < v.size(); i++) {
        Node *k = new Node(v[i]);
        auto [a, b] = _split(x, i);
        x = _merge(_merge(a, k), b);
    }
}

void _seg_add(Node *&x, int l, int r, int val) {
    auto [a, b] = _split(x, l);
    auto [ba, bb] = _split(b, r-l+1);
    if (ba) ba->add(val);
    x = _merge(a, _merge(ba, bb));
}

void _seg_set(Node *&x, int l, int r, int val) {
    auto [a, b] = _split(x, l);
    auto [ba, bb] = _split(b, r-l+1);
    if (ba) ba->set(val);
    x = _merge(a, _merge(ba, bb));
}

signed main() { WA();
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    Node *root;
    _build(root, v);
    while (q--) {
        int t, a, b, x;
        cin >> t;
        if (t == 1) {
            cin >> a >> b >> x;
            a--, b--;
            _seg_add(root, a, b, x);
        }
        else if (t == 2) {
            cin >> a >> b >> x;
            a--, b--;
            _seg_set(root, a, b, x);
        }
        else {
            cin >> a >> b;
            a--, b--;
            auto [l, r] = _split(root, a);
            auto [rl, rr] = _split(r, b-a+1);
            cout << rl->sum << '\n';
            root = _merge(l, _merge(rl, rr));
        }
    }
}


