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

vector<int> cntVec;
struct Node {
    int val, pri, _add, _cnt, _cntID, rev;
    Node *l, *r;

    Node(int x): val(x), pri(gen()), _cnt(0), _cntID(-1), _add(0), rev(0), l(nullptr), r(nullptr) {}
    
    void push() {
        if (_add) {
            val += _add;
            if (l) l->_add += _add;
            if (r) r->_add += _add;
            _add = 0;
        }
        if (_cnt) {
            if (~_cntID) cntVec[_cntID] += _cnt;
            if (l) l->_cnt += _cnt;
            if (r) r->_cnt += _cnt;
            _cnt = 0;
        }
    }
};

pair<Node *, Node *> _split(Node *x, int val) {
    if (!x) return {nullptr, nullptr};
    x->push();
    if (val <= x->val) {
        auto [a, b] = _split(x->l, val);
        x->l = b;
        return {a, x};
    }
    auto [a, b] = _split(x->r, val);
    x->r = a;
    return {x, b};
}

Node *_merge(Node *a, Node *b) {
    if (!a) return b;
    if (!b) return a;

    if (a->pri < b->pri) {
        a->push();
        a->r = _merge(a->r, b);
        return a;
    }
    b->push();
    b->l = _merge(a, b->l);
    return b;
}

void _dfs(Node *x) {
    if(!x) return;
    x->push();
    if (x->l) _dfs(x->l);
    if (x->r) _dfs(x->r);
}

void _inserTree(Node *&t, Node *n) {
    if (!n) return;
    n->push();
    Node *lt = n->l, *rt = n->r;
    n->l = n->r = nullptr;
    auto [a, b] = _split(t, n->val);
    t = _merge(_merge(a, n), b);
    _inserTree(t, lt); _inserTree(t, rt);
}

void _seg_buy(Node *&x, int price) {
    auto [a, b] = _split(x, price);
    if (b) {
        b->_add -= price;
        b->_cnt++;
    }
    auto [ba, bb] = _split(b, price);
    _inserTree(a, ba);
    x = _merge(a, bb);
}

signed main() { WA();
    int n; cin >> n;
    vector<PII> v(n);
    for (auto &i : v) cin >> i.fi >> i.se;
    cin >> n;
    vector<int> cus(n);
    cntVec.assign(n, 0);
    for(auto &i : cus) cin >> i;
    Node *root = nullptr;
    for (int i = 0; i < n; i++) {
        auto [a, b] = _split(root, cus[i]);
        Node *k = new Node(cus[i]);
        k->_cntID = i;
        root = _merge(_merge(a, k), b);
    }

    sort(all(v), [](PII a, PII b) {
        if (a.se == b.se) return a.fi < b.fi;
        return a.se > b.se;
    });

    for (int i = 0; i < v.size(); i++) {
        auto [c, q] = v[i];
        _seg_buy(root, c);
    }

    _dfs(root);

    for (auto &i : cntVec) cout << i << ' ';
}