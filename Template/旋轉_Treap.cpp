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

random_device rd;
mt19937 gen(rd());

struct Node;
inline int _getSiz(Node *x);

struct Node {
    Node* son[2]; // 0 為左子節點，1 為右節點
    int val, pri, cnt, siz;

    Node(int x) : val(x), cnt(1), siz(1), pri(gen()), son{nullptr, nullptr} {}

    void pull() {
        siz = cnt + _getSiz(son[0]) + _getSiz(son[1]);
    }
};

inline int _getSiz(Node *x) {
    return (x ? x->siz : 0);
}

enum rot {
    L = 1, R = 0
};

// 左旋為將根節點下放至左子樹，反之亦然

void _rotate(Node *&x, rot dir) {
    Node *y = x->son[dir];
    x->son[dir] = y->son[!dir];
    y->son[!dir] = x;
    x->pull(), y->pull();
    x = y;
}

void _insert(Node *&x, int val) {
    if (!x) return x = new Node(val), void();
    else if (val == x->val) x->cnt++, x->siz++;
    else if (val < x->val) {
        _insert(x->son[0], val);
        if (x->son[0]->pri < x->pri) _rotate(x, R);
        x->pull();
    }
    else {
        _insert(x->son[1], val);
        if (x->son[1]->pri < x->pri) _rotate(x, L);
        x->pull();
    }
}

void _delete(Node *&x, int val) {
    if (!x) return;
    if (val < x->val) _delete(x->son[0], val);
    else if (val > x->val) _delete(x->son[1], val);
    else {
        if (x->cnt > 1) x->cnt--, x->siz--;
        else {
            Node *y = x;
            if (x->son[0] && x->son[1]) {
                rot dir = (x->son[0]->pri < x->son[1]->pri ? R : L);
                _rotate(x, dir);
                _delete(x->son[!dir], val);
            }
            else if (x->son[0]) {
                x = y->son[0];
                delete y;
            }
            else if (x->son[1]) {
                x = y->son[1];
                delete y;
            }
            else {
                delete x;
                x = nullptr;
            }
        }
        if (x) x->pull();
    }
}

int queryRank(Node *x, int key) {
    if (!x) return -1;
    if (key == x->val) return _getSiz(x->son[0]) + 1;
    if (key < x->val) return queryRank(x->son[0], key);
    int qr = queryRank(x->son[1], key);
    if (~qr) return _getSiz(x->son[0]) + x->cnt + qr; // if (key > x->val)
    return -1;
}

int querykth(Node *x, int rank) {
    if (!x) return -1;
    if (x->son[0]) {
        if (x->son[0]->siz >= rank) return querykth(x->son[0], rank);
        if (x->son[0]->siz + x->cnt >= rank) return x->val;
    }
    else if (x->cnt >= rank) return x->val;
    return querykth(x->son[1], rank - _getSiz(x->son[0]) - x->cnt);
}

signed main() { WA();
    
}