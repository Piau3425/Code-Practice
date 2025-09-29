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
siz 以該節點的樹的總結點數，也就是 l->siz + cnt + r->siz
cnt 紀錄 val 值有幾個
l、r 為左右子樹
*/

struct Node;
inline int _getSiz(Node *x);

struct Node {
    Node *p, *l, *r;
    int val, siz, cnt;
    Node(int x) : p(nullptr), l(nullptr), r(nullptr), val(x), siz(1), cnt(1) {}

    void pull() {
        siz = _getSiz(l) + _getSiz(r) + cnt;
    }
};

inline int _getSiz(Node *x) {
    return (x ? x->siz : 0);
}

/*
根據插入的值與當前節點的值進行判斷
往左子樹或是右子樹遞迴
找到該節點適合的地方後
若為空節點就新增節點，已經存在則增加該節點的 cnt
*/

Node *_insert(Node *x, int val) {
    if (!x) return new Node(val);
    if (val < x->val) {
        x->l = _insert(x->l, val);
        x->l->p = x;
    }
    else if (val > x->val) {
        x->r = _insert(x->r, val);
        x->r->p = x;
    }
    else x->cnt++;
    x->pull();
    return x;
}

/*
遍歷方式為從最左邊的葉節點開始
在最右邊的葉節點結束
順序為左子樹 -> 當前節點 -> 右子樹
*/

void _traversal(Node *x) { // 初始 x 為根節點
    if (!x) return;
    _traversal(x->l);
    for (int i = 0; i < x->cnt; i++) cout << x->val << ' ';
    _traversal(x->r);
}

/*
判斷當前搜索的值小於大於節點
進行左子樹、右子樹的遞迴搜索
若值相等則當前節點為目標
*/

Node *_find(Node *x, int key) {
    if (!x) return nullptr;
    if (key == x->val) return x;
    if (key < x->val) return _find(x->l, key);
    return _find(x->r, key);
}

/*
最左邊的葉節點就是最小值
反之亦然
*/

Node *_find_Min(Node *x) {
    if (!x) return nullptr;
    while (x->l) x = x->l;
    return x;
}

Node *_find_Max(Node *x) {
    if (!x) return nullptr;
    while (x->r) x = x->r;
    return x;
}

/*
遞迴搜索到目標節點
如果 cnt 超過 1，則不用刪除該節點
刪除節點需要針對四種情況進行處理

- 左右子樹皆存在
需要找到一個替身並與之交換
為了維持性質可以選擇往左子樹找出最大值或是往右子樹找出最小值
之後遞迴刪除交換至底下的原節點
- 左子樹存在、右子樹不存在
刪除節點後
將左子樹向上替補與父節點相連
- 左子樹不存在、右子樹存在
同上
- 左右子樹皆不存在
直接刪除該節點
*/

Node *_delete(Node *x, int key) {
    if (!x) return x; // 沒找到 key 值
    if (key < x->val) { // 往下連接
        x->l = _delete(x->l, key);
        if (x->l) x->l->p = x;
    }
    else if (key > x->val) { // 往下連接
        x->r = _delete(x->r, key);
        if (x->r) x->r->p = x;
    }
    else {
        if (x->cnt > 1) x->cnt--;
        else {
            if (x->l && x->r) {
                Node *y = _find_Max(x->l); // 找到替身與當前節點互換
                x->val = y->val; x->cnt = y->cnt; // 底下的節點被換上來
                y->cnt = 1; // 但是換到下面的節點會被刪除，因此不用實作交換，但要記得將其出現次數該為 1
                x->l = _delete(x->l, y->val);
                if (x->l) x->l->p = x;
            }
            else if (x->l) {
                x->l->p = x->p; // x 的左子樹往上連接
                Node *ret = x->l;
                delete x;
                return ret;
            }
            else if (x->r) { // 同上
                x->r->p = x->p;
                Node *ret = x->r;
                delete x;
                return ret;
            }
            else {
                delete x;
                return nullptr;
            }
        }
    }
    x->pull();
    return x;
}

/*
查詢值是樹中的第幾元素
*/

int queryRank(Node *x, int key) {
    if (!x) return -1;
    if (key == x->val) return _getSiz(x->l) + 1;
    if (key < x->val) return queryRank(x->l, key);
    int qr = queryRank(x->r, key);
    if (~qr) return _getSiz(x->l) + x->cnt + qr; // if (key > x->val)
    return -1;
}

/*
查詢樹中第幾元素的值為何
*/

int querykth(Node *x, int rank) {
    if (!x) return -1;
    if (x->l) {
        if (x->l->siz >= rank) return querykth(x->l, rank);
        if (x->l->siz + x->cnt >= rank) return x->val;
    }
    else if (x->cnt >= rank) return x->val;
    return querykth(x->r, rank - _getSiz(x->l) - x->cnt);
}

signed main() { WA();

}