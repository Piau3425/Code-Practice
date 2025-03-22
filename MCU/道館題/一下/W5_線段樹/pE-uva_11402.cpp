/*
要交的作業都還沒寫 ...
*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

struct node {
    int sum = 0, setmark = -1, invmark = 0;
};

vector<int> v;
vector<node> tree;

void build(int l, int r, int now) {
    if (l == r) return void(tree[now].sum = v[l]);

    int m = (l+r) / 2;
    build(l, m, now*2), build(m+1, r, now*2+1);
    tree[now].sum = tree[now*2].sum + tree[now*2+1].sum;
}

void pd(int ql, int qr, int now) {
    int m = (ql+qr) / 2;

    if (~tree[now].setmark) {
        tree[now*2].sum = tree[now].setmark * (m-ql+1);
        tree[now*2+1].sum = tree[now].setmark * (qr-m);
        tree[now*2].setmark = tree[now*2+1].setmark = tree[now].setmark;
        tree[now].setmark = -1;
        tree[now*2].invmark = tree[now*2+1].invmark = 0;
    }
    if (tree[now].invmark) {
        tree[now*2].sum = (m-ql+1) - tree[now*2].sum;
        tree[now*2+1].sum = (qr-m) - tree[now*2+1].sum;
        tree[now*2].invmark = !tree[now*2].invmark;
        tree[now*2+1].invmark = !tree[now*2+1].invmark;
        tree[now].invmark = 0;
    }
}

void Set(int l, int r, int ql, int qr, int now, int k) {
    if (l <= ql && qr <= r) {
        tree[now].sum = k * (qr-ql+1);
        tree[now].setmark = k;
        tree[now].invmark = 0;
        return;
    }

    int m = (ql+qr) / 2;
    if ((~tree[now].setmark || tree[now].invmark) && ql != qr) pd(ql, qr, now);

    if (l <= m) Set(l, r, ql, m, now*2, k);
    if (r >= m+1) Set(l, r, m+1, qr, now*2+1, k);
    tree[now].sum = tree[now*2].sum + tree[now*2+1].sum;
}

void inverse(int l, int r, int ql, int qr, int now) {
    if (l <= ql && qr <= r) {
        tree[now].sum = (qr-ql+1) - tree[now].sum;
        tree[now].invmark = !tree[now].invmark;
        return;
    }

    int m = (ql+qr) / 2;
    if ((~tree[now].setmark || tree[now].invmark) && ql != qr) pd(ql, qr, now);

    if (l <= m) inverse(l, r, ql, m, now*2);
    if (r >= m+1) inverse(l, r, m+1, qr, now*2+1);
    tree[now].sum = tree[now*2].sum + tree[now*2+1].sum;
}

int query(int l, int r, int ql, int qr, int now) {
    if (l <= ql && qr <= r) return tree[now].sum;

    int m = (ql+qr) / 2, sum = 0;
    if ((~tree[now].setmark || tree[now].invmark)) pd(ql, qr, now);

    if (l <= m) sum += query(l, r, ql, m, now*2);
    if (r >= m+1) sum += query(l, r, m+1, qr, now*2+1);
    return sum;
}

signed main() { WA();
    int T; cin >> T;
    for (int Case = 1; Case <= T; Case++) { cout << "Case " << Case << ":\n";
        int m; v.assign(1, 0);

        for (cin >> m; m; m--) {
            int t; string s; cin >> t >> s;
            while (t--) for (auto c : s) v.pb(c - '0');
        }

        int n = v.size()-1;
        tree.resize(4*n);
        build(1, n, 1);

        int q; cin >> q;
        for (int i = 1; q; q--) { 
            char cmd; int a, b;
            cin >> cmd >> a >> b; a++, b++;
            if (cmd == 'F') Set(a, b, 1, n, 1, 1);
            else if (cmd == 'E') Set(a, b, 1, n, 1, 0);
            else if (cmd == 'I') inverse(a, b, 1, n, 1);
            else cout << "Q" << i++ << ": " << query(a, b, 1, n, 1) << '\n';
        }
        tree.clear(); // 用 resize 忘記 clear
    }
}