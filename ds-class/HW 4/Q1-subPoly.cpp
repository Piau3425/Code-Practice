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
    Poly(): head(new Node(0, -99999)), tail(head), size(0) {
        head->next = head;
    }
    ~Poly() {
        for (Node *now = head->next; now != head;) {
            Node *t = now;
            now = now->next;
            delete t;
        } delete head;
    }

    void push_back(Node *node) {
        size++;
        tail->next = node;
        tail = tail->next;
        tail->next = head;
    }

    Poly *sub(Poly &other) {
        Poly *ret = new Poly();
        for (Node *i = this->head->next, *j = other.head->next; i != this->head || j != other.head;) {
            if (i->exp > j->exp) ret->pb(new Node(i->coef, i->exp)), i = i->next;
            else if (i->exp < j->exp) ret->pb(new Node(-j->coef, j->exp)), j = j->next;
            else {
                if (i->coef - j->coef) ret->pb(new Node(i->coef-j->coef, i->exp));
                i = i->next, j = j->next;
            }
        }
        return ret;
    }

    void print() {
        cout << size << '\n';
        for (Node *now = head->next; now != head; now = now->next) cout << now->coef << ' ' << now->exp << '\n';
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
    Poly *ans = a.sub(b);
    ans->print();
    delete ans;
}

signed main() { WA();
    for (int n; cin >> n;) {
        solve(n);
    }
}