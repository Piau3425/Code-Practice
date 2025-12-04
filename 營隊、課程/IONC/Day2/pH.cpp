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

int bs(vector<int> &v, int l, int r, int tar) {
    int btm = l-1, ans = -1;
    while (l <= r) {
        int mid = l+((r-l)>>1);
        if (v[mid]-v[btm] < tar) {
            l = mid+1;
        }
        else if (v[mid]-v[btm] >= tar) {
            r = mid-1;
            ans = mid;
        }
    }
    return ans;
}

signed main() { WA();
    int n, q;
    cin >> n >> q;
    vector<int> v(n, 0), pf(n+1, 0);
    for (auto &i : v) cin >> i;
    for (int i = 1; i <= n; i++) pf[i] = pf[i-1] + v[i-1];
    while (q--) {
        int l, r; cin >> l >> r;
        int cnt = pf[r] - pf[l-1];
        if (cnt&1) {
            int k = bs(pf, l, r, (cnt+1)/2);
            cout << (~k ? k : -1) << '\n';
        }
        else if (cnt > 0) {
            int a = bs(pf, l, r, cnt/2), b = bs(pf, l, r, cnt/2+1);
            cout << (~a && ~b ? ((a+b)>>1) : -1) << '\n';
        }
        else cout << "-1\n";
    }
}