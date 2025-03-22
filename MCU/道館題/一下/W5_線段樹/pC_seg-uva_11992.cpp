/*
週六整天都耗在這裡了 ...
*/

#include <bits/stdc++.h>
using namespace std;

#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

struct node {
    int mx = 0, mn = 0, sum = 0, addmark = 0, setmark = -1;
};

vector<vector<node>> tree;

void pdset(int row, int l, int r, int now) {
    int m = (l+r) / 2;
    tree[row][now*2].sum = tree[row][now].setmark * (m-l+1);
    tree[row][now*2+1].sum = tree[row][now].setmark * (r-m);
    tree[row][now*2].mx = tree[row][now*2+1].mx = tree[row][now].setmark;
    tree[row][now*2].mn = tree[row][now*2+1].mn = tree[row][now].setmark;
    tree[row][now*2].setmark = tree[row][now*2+1].setmark = tree[row][now].setmark;
    tree[row][now].setmark = -1;
    tree[row][now*2].addmark = tree[row][now*2+1].addmark = 0;
}

void pdadd(int row, int l, int r, int now) {
    int m = (l+r) / 2;
    tree[row][now*2].sum += tree[row][now].addmark * (m-l+1);
    tree[row][now*2+1].sum += tree[row][now].addmark * (r-m);
    tree[row][now*2].mx += tree[row][now].addmark;
    tree[row][now*2+1].mx += tree[row][now].addmark;
    tree[row][now*2].mn += tree[row][now].addmark;
    tree[row][now*2+1].mn += tree[row][now].addmark;
    tree[row][now*2].addmark += tree[row][now].addmark;
    tree[row][now*2+1].addmark += tree[row][now].addmark;
    tree[row][now].addmark = 0;
}

void Add(int row, int l, int r, int ql, int qr, int now, int k) {
    if (l <= ql && qr <= r) {
        tree[row][now].sum += (qr-ql+1) * k;
        tree[row][now].addmark += k;
        tree[row][now].mx += k;
        tree[row][now].mn += k;
        return;
    }

    int m = (ql+qr) / 2;

    if (~tree[row][now].setmark && ql != qr) pdset(row, ql, qr, now);
    if (tree[row][now].addmark && ql != qr) pdadd(row, ql, qr, now);

    if (l <= m) Add(row, l, r, ql, m, now*2, k);
    if (r >= m+1) Add(row, l, r, m+1, qr, now*2+1, k);
    tree[row][now].sum = tree[row][now*2].sum + tree[row][now*2+1].sum;
    tree[row][now].mx = max(tree[row][now*2].mx, tree[row][now*2+1].mx);
    tree[row][now].mn = min(tree[row][now*2].mn, tree[row][now*2+1].mn);
}

void Set(int row, int l, int r, int ql, int qr, int now, int k) {
    if (l <= ql && qr <= r) {
        tree[row][now].sum = (qr-ql+1) * k;
        tree[row][now].mx = tree[row][now].mn = tree[row][now].setmark = k;
        tree[row][now].addmark = 0;
        return;
    }
    
    int m = (ql+qr) / 2;
    if (~tree[row][now].setmark && ql != qr) pdset(row, ql, qr, now);
    if (tree[row][now].addmark && ql != qr) pdadd(row, ql, qr, now);

    if (l <= m) Set(row, l, r, ql, m, now*2, k);
    if (r >= m+1) Set(row, l, r, m+1, qr, now*2+1, k);
    tree[row][now].sum = tree[row][now*2].sum + tree[row][now*2+1].sum;
    tree[row][now].mx = max(tree[row][now*2].mx, tree[row][now*2+1].mx);
    tree[row][now].mn = min(tree[row][now*2].mn, tree[row][now*2+1].mn);
}

tuple<int, int, int> query(int row, int l, int r, int ql, int qr, int now) {
    if (l <= ql && qr <= r) return {tree[row][now].sum, tree[row][now].mn, tree[row][now].mx};

    int m = (ql+qr) / 2;
    if (~tree[row][now].setmark) pdset(row, ql, qr, now);
    if (tree[row][now].addmark) pdadd(row, ql, qr, now);

    tuple<int, int, int> lq, rq; lq = rq = {0, 1e9, -1e9};
    if (l <= m) lq = query(row, l, r, ql, m, now*2);
    if (r >= m+1) rq = query(row, l, r, m+1, qr, now*2+1);

    return {get<0>(lq) + get<0>(rq), min(get<1>(lq), get<1>(rq)), max(get<2>(lq), get<2>(rq))};
}

signed main() { WA();
    int r, c, m;
    while (cin >> r >> c >> m) {
        tree.assign(r, vector<node>(4*c));
        while (m--) {
            int cmd, x1, x2, y1, y2, k;
            cin >> cmd >> x1 >> y1 >> x2 >> y2;
            x1--, x2--;
            if (cmd == 1 && cin >> k) for (int i = x1; i <= x2 ; i++) Add(i, y1, y2, 1, c, 1, k);
            else if (cmd == 2 && cin >> k) for (int i = x1; i <= x2; i++) Set(i, y1, y2, 1, c, 1, k);
            else {
                int mx = -1e9, mn = 1e9, sum = 0;
                for (int i = x1; i <= x2; i++) {
                    auto [qsum, qmn, qmx] = query(i, y1, y2, 1, c, 1);
                    mx = max(mx, qmx);
                    mn = min(mn, qmn);
                    sum += qsum;
                }
                cout << sum << ' ' << mn << ' ' << mx << '\n';
            }
        }
    }
}