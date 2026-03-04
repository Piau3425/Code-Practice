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

const int MOD = 998244353;

int power(int a, int b) {
    int ret = 1;
    for (; b; b >>= 1, a = a*a % MOD) if (b&1) ret = ret*a % MOD;
    return ret;
}
inline int _inv(int x) { return power(x, MOD-2); }

int total, sum;
vector<int> v, bit_cnt, bit_sum;

inline void _add(vector<int> &bit, int p, int val) {
    for (; p < bit.size(); p += p&-p) bit[p] += val;
}

inline int _query(vector<int> &bit, int p) { 
    int ret = 0;
    for (; p; p -= p&-p) ret += bit[p];
    return ret;
}

inline int _getKth(int k) {
    int p = 0;
    for (int i = 18; ~i; i--) if (p+(1<<i) < bit_cnt.size() && bit_cnt[p+(1<<i)] < k) p += 1<<i, k -= bit_cnt[p];
    return p+1;
}

inline int _getL(int p) {
    int c = _query(bit_cnt, p-1), s = _query(bit_sum, p-1);
    return c * v[p-1] - s;
}
inline int _getR(int p) {
    int c = total - _query(bit_cnt, p), s = sum - _query(bit_sum, p);
    return s - c * v[p-1];
}


inline int _fL(int k, int i) {
    return k == 1 ? 0 : _getL(_getKth(k-1));
}
inline int _fR(int k, int i) {
    return k == i ? 0 : _getR(_getKth(k+1));
}

signed main() { WA();
    int m; cin >> m;
    vector<int> a(m); for (auto &i : a) cin >> i;
    v = a; sort(all(v));
    v.erase(unique(all(v)), v.end());
    
    bit_cnt.assign(m+1, 0);
    bit_sum.assign(m+1, 0);

    for (int i = 1; i <= m; i++) {
        int p = lower_bound(all(v), a[i-1]) - v.begin() + 1;
        _add(bit_cnt, p, 1), _add(bit_sum, p, a[i-1]);
        total++, sum += a[i-1];

        if (i < 3) continue;

        int l = 1, r = i, pos = 1;
        while (l <= r) {
            int mid = (l+r) >> 1;
            if (_fL(mid, i) <= _fR(mid, i)) pos = mid, l = mid+1;
            else r = mid-1;
        }

        int ans = max(_fL(pos, i), _fR(pos, i));
        if (pos < i) ans = min(ans, max(_fL(pos+1, i), _fR(pos+1, i)));

        cout << (ans%MOD) * _inv(i-2) % MOD << '\n';
    }
}