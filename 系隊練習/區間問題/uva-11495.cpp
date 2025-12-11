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

vector<int> v, bit;
int n;

void upd(int x) {
    for (; x <= n; x += x&-x) bit[x]++;
}

int query(int x) {
    int ret = 0;
    for (; x; x -= x&-x) ret += bit[x];
    return ret;
}

signed main() { WA();
    for (; cin >> n, n;) {
        v.assign(n, 0); bit.assign(n+1, 0);
        for (auto &i : v) cin >> i;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += i - query(v[i]);
            upd(v[i]);
        }
        if (cnt&1) cout << "Marcelo\n";
        else cout << "Carlos\n";
    }
}