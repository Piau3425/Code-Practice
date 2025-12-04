/*
這次把線段樹手刻出來了
但是 ... 單點修改好像不需要懶標記阿！！！
所以我又把無腦刻出來的懶標記刪掉了，省了好多空間 :D
*/

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

vector<int> tree, v;
int t, n;

void build(int l, int r, int now) {
    if (l == r) return void(tree[now] = v[l]);

    int m = (l+r) / 2;
    build(l, m, now*2), build(m+1, r, now*2+1);
    tree[now] = tree[now*2] + tree[now*2+1];
}

void upd(int idx, int ql, int qr, int now, int k) {
    if (ql == qr) return void(tree[now] += k);

    int m = (ql+qr) / 2;
    if (idx <= m) upd(idx, ql, m, now*2, k);
    else upd(idx, m+1, qr, now*2+1, k);
    tree[now] = tree[now*2] + tree[now*2+1];
}

int query(int l, int r, int ql, int qr, int now) {
    if (l <= ql && qr <= r) return tree[now];

    int m = (ql+qr) / 2, sum = 0;
    if (l <= m) sum += query(l, r, ql, m, now*2);
    if (r >= m+1) sum += query(l, r, m+1, qr, now*2+1);
    return sum;
}


signed main() { WA();
    cin >> t;
    for (int Case = 1; Case <= t; Case++) { cout << "Case " << Case << ":\n";
        cin >> n;
        v.assign(n+1, 0);
        tree.assign(4*n, 0);
        for (int i = 1; i <= n; i++) cin >> v[i];
        build(1, n, 1);

        string cmd; int ii, jj;
        while (cin >> cmd, cmd != "End") {
            cin >> ii >> jj;
            if (cmd == "Query") cout << query(ii, jj, 1, n, 1) << endl;
            else upd(ii, 1, n, 1, jj*(cmd == "Add" ? 1 : -1));
        }
    }
}