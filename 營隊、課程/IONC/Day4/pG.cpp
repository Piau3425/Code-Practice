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

int n, q;
vector<int> bit, v, xit;

void update(int x, int val) {
    for (; x <= n; x += x&-x) bit[x] += val;
}

int query(int x) {
    int sum = 0;
    for (; x; x -= x&-x) sum += bit[x];
    return sum;
}

void upd(int x, int d){
    while (x <= n){
        xit[x] ^= d;
        x += x & (-x);
    }
}
int que(int x){
    int ret = 0;
    while (x){
        ret ^= xit[x];
        x -= x & (-x);
    }
    return ret;
}

signed main() { WA();
    while (cin >> n >> q) {
        bit.assign(n+1, 0);
        v.assign(n, 0);
        xit.assign(n+1, 0);
        for (auto &i : v) cin >> i;
        for (int i = 0; i < n; i++) update(i+1, v[i]);
        while (q--) {
            int cmd, l, r;
            cin >> cmd;
            if (cmd == 1) {
                cin >> l >> r;
                for (int i = l; i <= r; i++) {
                    update(i, i-l+1);
                }
            }
            else {
                cin >> l;
                cout << query(l) - query(l-1) << '\n';
            }
        }

        for (int i = 0; i < n; i++) v[i] = query(i+1) - query(i);
        for (int i = 1; i <= n; i++) upd(i, v[i-1]);
        
        cin >> q;
        while (q--) {
            int a, b; cin >> a >> b;
            cout << query(b) - query(a-1) << ' ' << (que(b)^que(a-1)) << '\n';
        }
    }
}