/*
對不起我還不會線段樹
所以我用 BIT + 差分
附上大神筆記：https://hackmd.io/@wiwiho/cp-note/%2F%40wiwiho%2FCPN-binary-indexed-tree#%E6%87%89%E7%94%A8
*/ 

#include <bits/stdc++.h>
using namespace std;

#define WA() cin.tie(0)->sync_with_stdio(0)
#define int long long
#define lowbit(x) x&-x

vector<int> B1, B2, v;
int n, m;

void add(int idx, int k) {
    for (int i = idx; i <= n; i += lowbit(i)) B1[i] += k, B2[i] += k*idx;
}

int query(int idx) {
    int sum = 0;
    for (int i = idx; i; i -= lowbit(i)) sum += (idx+1) * B1[i] - B2[i];
    return sum;
}

signed main() { WA();
    cin >> n >> m;
    v.assign(n+1, 0);
    B1.assign(n+1, 0);
    B2.assign(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        add(i, v[i] - v[i-1]);
    }
    while (m--) {
        int cmd, x, y, k;
        cin >> cmd >> x >> y;
        if (cmd == 1) {
            cin >> k;
            add(x, k);
            add(y+1, -k);
        }
        else cout << query(y) - query(x-1) << '\n';
    }
}