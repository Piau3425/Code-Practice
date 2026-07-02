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

int n;
vector<int> v, bit, k;

void upd(int x) {
    for (int i = x; i <= n; i += i&-i) bit[i] += 1;
}

int query(int x) {
    int sum = 0;
    for (int i = x; i; i -= i&-i) sum += bit[i];
    return sum;
}

signed main() { WA();
    for (; cin >> n;) {
        v.assign(n, 0);
        bit.assign(n+1, 0);
        for (auto &i : v) cin >> i;
        k = v; sort(all(k));
        for (auto &i : v) i = lower_bound(all(k), i) - k.begin() + 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += i - query(v[i]);
            upd(v[i]);
        }
        cout << ans << '\n';
    }
}