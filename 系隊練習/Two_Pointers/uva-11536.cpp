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
    int t, T = 1;
    for (cin >> t; T <= t; T++) { cout << "Case " << T << ": ";
        int n, m, k; cin >> n >> m >> k;
        vector<int> v(n+1); v[1] = 1, v[2] = 2, v[3] = 3;
        for (int i = 4; i <= n; i++) v[i] = (v[i-1]+v[i-2]+v[i-3])%m+1;
        int mn = INF;
        set<int> st; vector<int> cnt(k+1);
        for (int ldx = 1, rdx = 1; rdx <= n; rdx++) {
            if (v[rdx] <= k) {
                if (!cnt[v[rdx]]) st.insert(v[rdx]);
                cnt[v[rdx]]++;
            }
            
            while (st.size() == k) {
                mn = min(mn, rdx-ldx+1);
                if (v[ldx] <= k) {
                    cnt[v[ldx]]--;
                    if (!cnt[v[ldx]]) st.erase(v[ldx]);
                }
                ldx++;
            }
        }
        if (mn == INF) cout << "sequence nai\n";
        else cout << mn << '\n';
    } 
}