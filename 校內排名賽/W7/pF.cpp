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

int n, m;
vector<int> v, neg, zero;

void upd(vector<int> &bit, int idx, int val) {
    for (; idx <= n; idx += idx&-idx) bit[idx] += val;
}

int query(vector<int> &bit, int idx) {
    int sum = 0;
    for (; idx; idx -= idx&-idx) sum += bit[idx];
    return sum;
}

signed main() { WA();
    while (cin >> n >> m) {
        v.assign(n+1, 0); neg.assign(n+1, 0); zero.assign(n+1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            if (v[i] < 0) upd(neg, i, 1);
            if (v[i] == 0) upd(zero, i, 1);
        }
        while (m--) {
            char c; int a, b;
            cin >> c >> a >> b;
            if (c == 'C') {
                if (v[a] < 0) upd(neg, a, -1);
                if (v[a] == 0) upd(zero, a, -1);
                v[a] = b;
                if (v[a] < 0) upd(neg, a, 1);
                if (v[a] == 0) upd(zero, a, 1);
            }
            else {
                if (query(zero, b)-query(zero, a-1) > 0) cout << 0;
                else if ((query(neg, b)-query(neg, a-1))&1) cout << '-';
                else cout << '+';
            }
        }
        cout << '\n';
    }
}