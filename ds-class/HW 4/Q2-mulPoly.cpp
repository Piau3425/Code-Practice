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

struct Node {
    int coef, exp;
    Node *next;
    Node(int c, int e): coef(c), exp(e), next(nullptr) {}
};

struct Poly {
    Node *head, *tail;
    int size;
    Poly(): head(new Node(0, -99999)), tail(head), size(0) {}
    ~Poly() {
        for (Node *now = head; now;) {
            Node *t = now;
            now = now->next;
            delete t;
        }
    }

    void push_back(Node *node) {
        size++;
        tail = tail->next = node;
    }

    void delNodeAfter(Node *x) {
        Node *p = x->next;
        x->next = x->next->next;
        delete p;
    }

    void insert_sorted(Node *node) {
        Node *now = head;
        for (; now->next && now->next->exp > node->exp; now = now->next);
        if (now->next && now->next->exp == node->exp) {
            if (now->next->coef + node->coef) now->next->coef += node->coef;
            else {
                if (tail == now->next) tail = now;
                delNodeAfter(now);
                size--;
            }
            delete node;
        }
        else {
            size++, node->next = now->next, now->next = node;
            if (now == tail) tail = node;
        }
    }

    Poly *mul(Poly &other) {
        Poly *ret = new Poly();
        for (Node *i = this->head->next; i; i = i->next)
        for (Node *j = other.head->next; j; j = j->next)
        if (i->coef * j->coef) ret->insert_sorted(new Node(i->coef * j->coef, i->exp + j->exp));
        return ret;
    }

    void print() {
        cout << size << '\n';
        for (Node *now = head->next; now; now = now->next) cout << now->coef << ' ' << now->exp << '\n';
    }
};

void solve(int n) {
    Poly a, b;
    while (n--) {
        int p, q; cin >> p >> q;
        a.pb(new Node(p, q));
    }
    int m; for (cin >> m; m--;) {
        int p, q; cin >> p >> q;
        b.pb(new Node(p, q));
    }
    Poly *ans = a.mul(b);
    ans->print();
    delete ans;
}

signed main() { WA();
    for (int n; cin >> n;) {
        solve(n);
    }
}