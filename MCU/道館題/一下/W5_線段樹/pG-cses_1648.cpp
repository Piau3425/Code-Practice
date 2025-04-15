#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> v, bit;
int n, m;

void upd(int idx, int val) {
    for (; idx <= n; idx += idx&-idx) bit[idx] += val;
}

int get(int a, int b) {
    int sa = 0, sb = 0; a--;
    for (; a > 0; a -= a&-a) sa += bit[a];
    for (; b > 0; b -= b&-b) sb += bit[b];
    return sb-sa;
}

signed main() { ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    v.resize(n+1); bit.resize(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        upd(i, v[i]);
    }
    while (m--) {
        int c, a, b;
        cin >> c >> a >> b;
        if (c == 1) {
            upd(a, -v[a]);
            v[a] = b;
            upd(a, b);
        }  
        else cout << get(a, b) << '\n';
    }
}