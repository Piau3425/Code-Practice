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
    set<int> st;
    int n, m;
    for (cin >> n >> m; n--;) {
        int k, flag = 1; 
        for (cin >> k; k--;) {
            int t; cin >> t;
            if (st.count(t)) continue;
            if (flag) {
                st.insert(t);
                cout << t << '\n', flag = 0;
            }
        }
        if (flag) cout << 0 << '\n';
    }
}