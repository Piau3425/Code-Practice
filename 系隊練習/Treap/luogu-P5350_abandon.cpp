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
const int p = 1000000007;

struct Node;
inline int _getSiz(Node *x);
inline int _getSum(Node *x);

struct Node {
    int val, sum, pri, siz, _add, _set_tag, _set_val, rev;
    Node *l, *r;

    Node(int x): val(x), sum(x), pri(gen()), siz(1), _add(0), _set_tag(0), _set_val(0), rev(0), l(nullptr), r(nullptr) {}

    inline void pull() {
        siz = _getSiz(l) + _getSiz(r) + 1;
        sum = _getSum(l) + _getSum(r) + val;
        while (sum >= p) sum -= p;
    }

    void set(int k) {
        _set_tag = 1;
        _set_val = k % p;
        _add = 0;
        val = k % p;
        sum = siz * k % p;
    }

    void add(int k) {
        if (_set_tag) _set_val = (_set_val+k) % p;
        else _add = (_add+k) % p;
        val = (val+k) % p;
        sum = (sum+siz * k) % p;
    }
    
    void push() {
        if (_set_tag || rev || _add) {
            if (l) l = _copy(l);
            if (r) r = _copy(r);
        }
        if (_set_tag) {
            if (l) l->set(_set_val);
            if (r) r->set(_set_val);
            _set_tag = 0;
        }
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

inline int _getSum(Node *x) {
    return (x ? x->sum : 0);
}

vector<Node> pool(4000003);
int cnt = 0;

inline Node *_new(int val) {
    Node *x = &pool[cnt++];
    x->val = x->sum = val;
    x->pri = gen();
    x->siz = 1;
    x->_add = x->_set_tag = x->_set_val = x->rev = 0;
    x->l = x->r = nullptr;
    return x;
}

inline Node *_copy(Node *x) {
    Node *y = &pool[cnt++];
    y->val = x->val;
    y->pri = x->pri;
    y->sum = x->sum;
    y->siz = x->siz;
    y->_add = x->_add;
    y->_set_tag = x->_set_tag;
    y->_set_val = x->_set_val;
    y->rev = x->rev;
    y->l = x->l;
    y->r = x->r;
    return y;
}

Node *_build_rec(vector<int> &v, int l, int r) {
    if (l > r) return nullptr;
    int mid = (l+r) / 2;
    Node *x = _new(v[mid]);
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

/*
直接使用 split by size
因為 size 就是 index
*/

pair<Node *, Node *> _split(Node *x, int sz) {
    if (!x) return {nullptr, nullptr};
    x->push();
    x = _copy(x);
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

    if (a->pri < b->pri) {
        a = _copy(a);
        a->push();
        a->r = _merge(a->r, b);
        a->pull();
        return a;
    }
    else {
        b = _copy(b);
        b->push();
        b->l = _merge(a, b->l);
        b->pull();
        return b;
    }
}

void _seg_rev(Node *&x, int l, int r) {
    auto [a, b] = _split(x, l);
    auto [ba, bb] = _split(b, r-l+1);
    if (ba) ba->rev ^= 1;
    x = _merge(a, _merge(ba, bb));
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

void _seg_dup(Node *&x, int l1, int r1, int l2, int r2) {
    bool flag = false;
    if (l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
        flag = true;
    }

    auto [a, t1] = _split(x, l1);
    auto [seg1, t2] = _split(t1, r1-l1+1);
    auto [mid, t3] = _split(t2, l2-r1-1);
    auto [seg2, b] = _split(t3, r2-l2+1);
    if (!flag) seg2 = _copy(seg1);
    else seg1 = _copy(seg2);
    x = _merge(a, _merge(seg1, _merge(mid, _merge(seg2, b))));
}

void _seg_swap(Node *&x, int l1, int r1, int l2, int r2) {
    if (l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    auto [a, t1] = _split(x, l1);
    auto [seg1, t2] = _split(t1, r1-l1+1);
    auto [mid, t3] = _split(t2, l2-r1-1);
    auto [seg2, b] = _split(t3, r2-l2+1);
    x = _merge(a, _merge(seg2, _merge(mid, _merge(seg1, b))));
}

int _query(Node *&x, int l, int r) {
    auto [a, b] = _split(x, l);
    auto [ba, bb] = _split(b, r-l+1);
    int ret;
    if (ba) ret = ba->sum;
    x = _merge(a, _merge(ba, bb));
    return ret;
}

int idx;
vector<int> v;

void dfs(Node *x) {
    if (!x) return;
    x->push();
    if (x->l) dfs(x->l);
    v[idx++] = x->val;
    if (x->r) dfs(x->r);
}

signed main() { WA();
    int n, m; cin >> n >> m;
    v.reserve(n);
    for (auto &i : v) cin >> i;
    Node *root;
    root = _build_rec(v, 0, n-1);
    while (m--) {
        int cmd, a, b, c, d, k;
        cin >> cmd;
        if (cmd == 1) {
            cin >> a >> b;
            a--, b--;
            cout << _query(root, a, b) % p << '\n';
        }
        else if (cmd == 2) {
            cin >> a >> b >> k;
            a--, b--;
            _seg_set(root, a, b, k);
        }
        else if (cmd == 3) {
            cin >> a >> b >> k;
            a--, b--;
            _seg_add(root, a, b, k);
        }
        else if (cmd == 4) {
            cin >> a >> b >> c >> d;
            a--, b--, c--, d--;
            _seg_dup(root, a, b, c, d);
        }
        else if (cmd == 5) {
            cin >> a >> b >> c >> d;
            a--, b--, c--, d--;
            _seg_swap(root, a, b, c, d);
        }
        else {
            cin >> a >> b;
            a--, b--;
            _seg_rev(root, a, b);
        }
        if (cnt > 3600000) {
            idx = 0;
            dfs(root);
            root = _build_rec(v, 0, n-1);
            cnt = 0;
        }
    }
    _traversal(root);
}