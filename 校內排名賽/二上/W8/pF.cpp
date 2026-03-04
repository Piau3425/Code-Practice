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
    for (int n, m; cin >> n >> m;) {
        vector<int> ans, v;
        int mx = -1e9;
        while (m--) {
            int k; cin >> k;
            v.assign(k, 0);
            for (auto &i : v) cin >> i;
            for (int i = n; i--;) {
                set<int> st;
                for (int i = 0; i < v.size(); i++) for (int j = i+1; j < v.size(); j++) st.insert(v[i]+v[j]);
                v.clear();
                for (auto &i : st) v.pb(i);
            }
            int i;
            for (i = 0; i < v.size(); i++) if (v[i] != i+1) break;
            cout << i-1 << '\n';
        }
    }
}