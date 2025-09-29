/*
我可能看懂線段樹了？
附上文章：
https://cp.wiwiho.me/segment-tree/
https://oi-wiki.org/ds/seg/
*/

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

vector<int> tree, v, mark;
int n, m, x, y, k, cmd;

void build(int l, int r, int now) {
    if (l == r) return void(tree[now] = v[l]); // 若區間只剩一個元素，即為葉節點，將樹的該節點放入原陣列值

    int m = (l+r) / 2;
    build(l, m, now*2), build(m+1, r, now*2+1); // 往兩子節點繼續建樹
    tree[now] = tree[now*2] + tree[now*2+1]; // 合併兩子節點的值至父節點
}

// [l, r] 查詢區間，now 當前節點，[ql, qr] 當前遞迴區間
int query(int l, int r, int ql, int qr, int now) {
    if (l <= ql && qr <= r) return tree[now]; // 如果當前遞迴區間位於查詢區間內，則直接回傳該區間的值

    int m = (ql+qr) / 2, sum = 0;
    // 下放懶標記
    if (mark[now]) { // 若懶標記存在
        tree[now*2] += mark[now] * (m-ql+1), tree[now*2 + 1] += mark[now] * (qr - m); // 對兩子節點補上懶標記值
        mark[now*2] += mark[now], mark[now*2 + 1] += mark[now]; // 懶標記下放兩子節點
        mark[now] = 0; // 清空當前節點 (區間) 的懶標記
    }
    // 當前遞迴的區間[ql, qr] 切成 左區間[ql, m] 和 右區間[m+1, qr]
    if (l <= m) sum += query(l, r, ql, m, now*2); // 如果 欲查詢區間[l, r] 在該遞迴的 左區間[ql, m] 有重疊，則往左節點向下遞迴
    if (r >= m+1) sum += query(l, r, m+1, qr, now*2+1); // 如果 欲查詢區間[l, r] 在該遞迴的 右區間[m+1, qr] 有重疊，則往右節點向下遞迴
    return sum; // 回傳查詢後合併的值
}

// [l, r] 欲修改區間，now 當前節點，[ql, qr] 當前遞迴區間，k 修改的值
void upd(int l, int r, int ql, int qr, int now, int k) {
    if (l <= ql && qr <= r) { // 如果目前遞迴的區間在修改區間內
        tree[now] += (qr-ql+1) * k, mark[now] += k; // 將該區間加上該值，並且打上懶標記
        return;
    }

    int m = (ql+qr) / 2;
    // 下放懶標記
    if (mark[now] && qr != ql) { // 如果當前存在懶標記，且不為葉節點 (葉節點下放沒意義)
        tree[now*2] += mark[now] * (m-ql+1), tree[now*2 + 1] += mark[now] * (qr-m); // 對兩子節點補上懶標記值
        mark[now*2] += mark[now], mark[now*2 + 1] += mark[now]; // 懶標記下放兩子節點
        mark[now] = 0; // 清空當前節點 (區間) 的懶標記 (已下放完成)
    }

    // 當前遞迴的區間[ql, qr] 切成 左區間[ql, m] 和 右區間[m+1, qr]
    if (l <= m) upd(l, r, ql, m, now*2, k); // 如果 欲修改區間[l, r] 與該遞迴的 左區間[ql, m] 有重疊，則往左節點向下遞迴
    if (r >= m+1) upd(l, r, m+1, qr, now*2+1, k); // 如果 欲修改區間[l, r] 與該遞迴的 右區間[m+1, qr] 有重疊，則往右節點向下遞迴
    tree[now] = tree[now*2] + tree[now*2 + 1]; // 合併兩子節點至父節點
}

signed main() { WA();
    cin >> n >> m;
    tree.assign(4*n, 0);
    v.assign(n+1, 0);
    mark.assign(4*n, 0);
    for (int i = 1; i <= n; i++) cin >> v[i];
    build(1, n, 1);

    while (m--) {
        cin >> cmd >> x >> y;
        if (cmd == 1) {
            cin >> k;
            upd(x, y, 1, n, 1, k);
        }
        else cout << query(x, y, 1, n, 1) << endl;
    }
}