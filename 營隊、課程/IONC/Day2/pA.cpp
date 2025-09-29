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

random_device rd;
mt19937 gen(rd());

struct Treap {
    Treap *l, *r;
    int key, pri, size, sum, tag;
    Treap(int k) : l(nullptr), r(nullptr), key(k), pri(gen()), size(1), sum(k), tag(0) {}

    void pull() {
        size = 1;
        sum = key;
        if (l) size += l->size, sum += l->sum;
        if (r) size += r->size, sum += r->sum;
    }

    void push() {
        if (!tag) return;
        key += tag;
        sum += tag * size;
        if (l) l->tag += tag, l->sum += tag * l->size;
        if (r) r->tag += tag, r->sum += tag * r->size;
        tag = 0;
    }
};

inline int sz(Treap *p) {
    return (p ? p->size : 0);
}

Treap *merge(Treap *a, Treap *b) {
    if (!a) return b;
    if (!b) return a;
    if (a->pri < b->pri) {
        a->push();
        a->r = merge(a->r, b);
        a->pull();
        return a;
    }
    else {
        b->push();
        b->l = merge(a, b->l);
        b->pull();
        return b;
    }
}

void split(Treap *p, Treap *&a, Treap *&b, int k) { 
    if (!p) return a = b = nullptr, void();
    p->push();
    if (sz(p->l) < k) {
        a = p;
        split(p->r, a->r, b, k-sz(p->l)-1);
        a->pull();
    }
    else {
        b = p;
        split(p->l, a, b->l, k);
        b->pull();
    }
}

int query(Treap *&root, int l, int r) {
    Treap *a, *b, *c;
    split(root, b, c, r);
    split(b, a, b, l-1);
    int ret = b->sum;
    root = merge(merge(a, b), c);
    return ret;
}

void add(Treap *&root, int l, int r, int k) {
    Treap *a, *b, *c;
    split(root, b, c, r);
    split(b, a, b, l-1);
    b->pull();
    b->tag += k;
    b->push();
    root = merge(merge(a, b), c);
}

signed main() { WA();
    int n, q;
    while (cin >> n >> q) {
        Treap *tp = nullptr;
        while (n--) {
            int k; cin >> k;
            tp = merge(tp, new Treap(k));
        }

        while (q--) {
            int cmd, l, r, k;
            cin >> cmd;
            if (cmd == 1) {
                Treap *a, *b;
                split(tp, a, b, 1);
                tp = merge(b, a);
            }
            else if (cmd == 2) {
                Treap *a, *b;
                split(tp, a, b, sz(tp)-1);
                tp = merge(b, a);
            }
            else if (cmd == 3) {
                cin >> l >> r >> k;
                add(tp, l, r, k);
            }
            else {
                cin >> l >> r;
                cout << query(tp, l, r) << '\n';
            }
        }
    }
}