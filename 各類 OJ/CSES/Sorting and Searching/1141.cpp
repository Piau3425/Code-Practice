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

signed main() { WA();
    int n; cin >> n; vector<int> v(n);
    for (auto &i : v) cin >> i;
    set<int> st; int mx = -1e9;
    for (int ldx = 0, rdx = 0; rdx < n; rdx++) {
        if (st.count(v[rdx])) do {st.erase(v[ldx]);} while (v[ldx++] != v[rdx]);
        st.insert(v[rdx]);
        mx = max(mx, (int)st.size());
    }
    cout << mx << '\n';
}