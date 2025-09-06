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

/*
val 值
pri 維護 Heap 的權重
siz 以該節點的樹的總結點數，也就是 l->siz + cnt + r->siz
cnt 紀錄 val 值有幾個
l、r 為左右子樹

此範例為 min_heap
*/
mt19937 rng(time(0));
struct Node {
    int val, pri, siz, cnt;
    Node *l, *r;

    Node(int x) : val(x), pri(rng()), siz(1), cnt(1), l(nullptr), r(nullptr) {}

    void pull() {
        siz = cnt + (l ? l->siz : 0) + (r ? r->siz : 0);
    }
};

/*
_split 將原 Treap x 分割成兩個 Treap，為 a 跟 b
其中所有的值符合
a：< key
b：>= key
*/

pair<Node *, Node *> _split(Node *x, int key) { // 使用方法：auto [a, b] = split(root, key);
    // base case: 當前節點為空節點
    if (!x) return {nullptr, nullptr};
    /*
    如果當前節點為 x
    x->val < key，同時 x->l 所有的值 < 當前節點的值
    因此當前節點及左子樹都會被分到 a
    並且無法確定所有大於 x 的值也就是 x->r 也全部 >= key，所以要向下遞迴從 x->r 中找出 < key 的部份分到 a，成為 x 的右子樹
    並且將真正 >= key 的值放到 b
    */
    if (x->val < key) {
        auto [a, b] = _split(x->r, key); // 往 x->r 遞迴
        x->r = a; // 遞迴切出來的 a 為大於 x 但是 <= key 的值
        x->pull();
        return {x, b};
    }
    // 相反同理
    else {
        auto [a, b] = _split(x->l, key);
        x->l = b;
        x->pull();
        return {a, x};
    }
}

/*
遞迴分割小於 rk、等於 rk、大於 rk
*/

tuple<Node *, Node *, Node *> splitByRank(Node *x, int rk) {
    if (!x) return {nullptr, nullptr, nullptr};
    int ls = (x->l ? x->l->siz : 0);
    if (rk <= ls) {
        auto [ll, mid, rr] = splitByRank(x->l, rk);
        x->l = rr; x->pull();
        return {ll, mid, x};
    }
    else if (rk <= ls + x->cnt) {
        Node *ll = x->l, *rr = x->r;
        x->l = x->r = nullptr;
        x->pull();
        return {ll, x, rr};
    }
    else {
        auto [ll, mid, rr] = splitByRank(x->r, rk);
        x->r = ll; x->pull();
        return {x, mid, rr};
    }
}

/*
前提：Treap a 的值 < Treap b 的值
所以在合併的時候只需要維護堆性質
*/

Node *_merge(Node *a, Node *b) {
    // 直到該左右子樹為空節點，則直接連上另一個 Treap
    if (!a) return b;
    if (!b) return a;

    /*
    如果 a 的權重 < b 的權重
    當前為 min_heap，所以將權重較小的 a 設為父節點，放在上方
    並且因為 b 所有的值比 a 所有的值大，所以按照樹的性質，要將 b 放在 a 的右子樹
    */

    if (a->pri < b->pri) {
        a->r = _merge(a->r, b); // 記得遵守前提
        a->pull();
        return a; // a 為父節點
    }
    // 相反同理
    else {
        b->l = _merge(a, b->l); // 記得遵守前提
        b->pull();
        return b;
    }
}

/*
先從 x 中切出 a: < val, b: >= val
再從 b 中切出 bl: < val+1, br: >= val+1
其中 bl 同時滿足 bl >= val 跟 bl < val+1，也就是說 bl 就是 val 本人
如果該節點存在，也就是說已經有了儲存 val 的節點，就將 cnt + 1 即可
否則需要創建一個新的節點
最後再將分割出來的三個 Treap 合併回去
*/

void _insert(Node *&x, int val) {
    auto [a, b] = _split(x, val);
    auto [bl, br] = _split(b, val+1);
    Node *k;
    if (bl) {
        bl->cnt++;
        bl->pull();
    }
    else bl = new Node(val);

    x = _merge(a, _merge(bl, br));
}

/*
跟 insert 同個概念
基本上想要對特定節點進行操作，流程大概就是這樣
*/

void _delete(Node *&x, int val) {
    auto [a, b] = _split(x, val);
    auto [bl, br] = _split(b, val+1);

    if (bl) { // 找得到該節點再進行 cnt 的判斷
        if (bl->cnt > 1) {
            bl->cnt--;
            bl->pull();
        }
        else {
            delete bl;
            bl = nullptr;
        }
    }

    x = _merge(a, _merge(bl, br));
}

int queryRankByVal(Node *x, int val) {
    auto [a, b] = _split(x, val);
    int ret = (a ? a->siz : -2) + 1;
    _merge(a, b);
    return ret;
}

int queryValByRank(Node *x, int rk) {
    auto [ll, mid, rr] = splitByRank(x, rk);
    return mid->val;
}

signed main() { WA();
    
}