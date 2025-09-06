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

struct Node {
    Node* son[2]; // 0 為左子節點，1 為右節點
    int val, pri, cnt, siz;

    Node(int x) : val(x), cnt(1), siz(1), pri(gen()), son{nullptr, nullptr} {}

    void pull() {
        siz = cnt + (son[0] ? son[0]->siz : 0) + (son[1] ? son[1]->siz : 0);
    }
};

enum rot {
    L = 1, R = 0 // 左旋為將根節點的右子節點為新的根結點，反之亦然
};

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
                x->pull();
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
    }
}

signed main() { WA();
    
}