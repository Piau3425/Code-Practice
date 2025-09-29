// 洛谷 P5350

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
    int l, r;
    mutable int v;

    Node(const int &il, const int &ir, const int &iv): l(il), r(ir), v(iv) {}

    bool operator<(const Node &o) const { return l < o.l; }
};

set<Node> odt;
const int p = 1e9+7;

inline Node *_copy(set<Node>::iterator x) {
    return new Node(x->l, x->r, x->v);
}

auto _split(int x) {
    auto it = odt.lower_bound(Node(x, 0, 0));
    if (it != odt.end() && it->l == x) return it;
    auto k = _copy(--it);
    odt.erase(it);
    odt.insert(Node(k->l, x-1, k->v));
    return odt.insert(Node(x, k->r, k->v)).fi;
}

int _query(int l, int r) {
    auto itr = _split(r+1), itl = _split(l);
    int sum = 0;
    for (; itl != itr; itl++) sum = (sum + itl->v%p * (itl->r - itl->l + 1)%p) % p;
    return sum;
}

void _assign(int l, int r, int v) {
    auto itr = _split(r+1), itl = _split(l);
    odt.erase(itl, itr);
    odt.insert(Node(l, r, v));
}

void _add(int l, int r, int v) {
    auto itr = _split(r+1), itl = _split(l);
    vector<Node> vec;
    for (auto it = itl; it != itr; it++) vec.emplace_back(*it), vec.back().v = (vec.back().v+v) % p;
    odt.erase(itl, itr);
    for (auto &i : vec) odt.insert(i);
}

void _dup(int l1, int r1, int l2, int r2) {
    auto itr1 = _split(r1+1), itl1 = _split(l1);
    vector<Node> vec;
    for (; itl1 != itr1; itl1++) vec.emplace_back(*itl1);
    auto itr2 = _split(r2+1), itl2 = _split(l2);
    odt.erase(itl2, itr2);
    for (auto &i : vec) odt.insert(Node(i.l-l1+l2, i.r-l1+l2, i.v));
}

void _swap(int l1, int r1, int l2, int r2) {
    if (l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    auto itr1 = _split(r1+1), itl1 = _split(l1);
    vector<Node> va, vb;
    for (auto it = itl1; it != itr1; it++) va.emplace_back(*it);
    auto itr2 = _split(r2+1), itl2 = _split(l2);
    for (auto it = itl2; it != itr2; it++) vb.emplace_back(*it);
    itr1 = _split(r1+1), itl1 = _split(l1); // 記得重新 split (l1, r1)，因為經過了 split (l2, r2) set 內已經變了
    odt.erase(itl1, itr1);
    itr2 = _split(r2+1), itl2 = _split(l2); // 同理
    odt.erase(itl2, itr2);
    for (auto &i : va) odt.insert(Node(i.l-l1+l2, i.r-l1+l2, i.v));
    for (auto &i : vb) odt.insert(Node(i.l-l2+l1, i.r-l2+l1, i.v));
}

void _rev(int l, int r) {
    if (l > r) swap(l, r); // !
    auto itr = _split(r+1), itl = _split(l);
    vector<Node> vec;
    for (auto it = itl; it != itr; it++) vec.emplace_back(*it);
    odt.erase(itl, itr);
    for (auto &i : vec) odt.insert(Node(r-i.r+l, r-i.l+l, i.v));
}

signed main() { WA();
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        odt.insert(Node(i, i, x));
    }
    while (m--) {
        int cmd, l1, l2, r1, r2, val;
        cin >> cmd >> l1 >> r1; l1--, r1--;
        if (cmd == 1) cout << _query(l1, r1) << '\n';
        else if (cmd == 2) {
            cin >> val;
            _assign(l1, r1, val);
        }
        else if (cmd == 3) {
            cin >> val;
            _add(l1, r1, val);
        }
        else if (cmd == 4) {
            cin >> l2 >> r2; l2--, r2--;
            _dup(l1, r1, l2, r2);
        }
        else if (cmd == 5) {
            cin >> l2 >> r2; l2--, r2--;
            _swap(l1, r1, l2, r2);
        }
        else _rev(l1, r1);
    }
    for (auto &i : odt) for (int j = i.l; j <= i.r; j++) cout << i.v%p << ' ';
}