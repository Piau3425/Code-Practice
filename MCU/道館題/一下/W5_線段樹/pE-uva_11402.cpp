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

vector<int> v, tree;

void build(int l, int r, int now) {
    if (l == r) return void(tree[now] == v[l]);

    int m = (l+r) / 2;
    build(l, m, now*2), build(m+1, r, now*2+1);
    tree[now] = tree[now*2] + tree[now*2+1];
}

void pd() {

}

void Set(int l, int r, int ql, int qr, int now, int k) {
    if (l <= ql && qr <= r) 
}

void inverse(int l, int r, int ql, int qr, int now) {

}

int query(int l, int r, int ql, int qr, int now) {

}

signed main() { WA();
    int T; cin >> T;
    for (int Case = 1; Case <= T; Case++) { cout << "Case " << Case << ":\n";
        int m; v.assign(1, 0);

        for (cin >> m; m; m--) {
            int t; string s; cin >> t >> s;
            while (t--) for (auto c : s) v.pb(c - '0');
            int n = (v.size()-1)*4;
            tree.assign(n, 0);
            build(1, n, 1);

            int q; 
            for (cin >> q; q; q--) {
                char cmd; int a, b;
                cin >> cmd >> a >> b;
                if (cmd == 'F') Set(a, b, 1, n, 1, 1);
                else if (cmd == 'E') Set(a, b, 1, n, 1, 0);
                else if (cmd == 'I') inverse(a, b, 1, n, 1);
                else query(a, b, 1, n, 1);
            }
        }
    }
}