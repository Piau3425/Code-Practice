/*
我不管
我還是不會線段樹
只好再塞一個上學期寫的 BIT 了
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
vector<int> v, neg, zero;

void upd(vector<int> &bit, int idx, int val) {
    for (; idx <= n; idx += idx&-idx) bit[idx] += val;
}

int get(vector<int> &bit, int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx&-idx) sum += bit[idx];
    return sum;
}

signed main() { ios::sync_with_stdio(0); cin.tie(0);
    while (cin >> n >> m) {
        v.resize(n+1); neg.resize(n+1, 0); zero.resize(n+1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            if (v[i] < 0) upd(neg, i, 1);
            if (v[i] == 0) upd(zero, i, 1);
        }
        while (m--) {
            char c;
            int a, b;
            cin >> c >> a >> b;
            if (c == 'C') {
                if (v[a] < 0) upd(neg, a, -1);
                if (v[a] == 0) upd(zero, a, -1);
                v[a] = b;
                if (v[a] < 0) upd(neg, a, 1);
                if (v[a] == 0) upd(zero, a, 1);
            }
            else {
                if (get(zero, b)-get(zero, a-1) > 0) cout << 0;
                else if (!((get(neg, b)-get(neg, a-1))&1)) cout << '+';
                else cout << '-';
            }
        }

        cout << '\n';
        v.clear(); neg.clear(); zero.clear();
    }
}