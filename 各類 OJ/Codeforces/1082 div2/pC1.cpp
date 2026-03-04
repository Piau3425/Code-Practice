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
    int t;
    for (cin >> t; t--;) {
        int n; cin >> n;
        vector<int> a(n); for (auto &i : a) cin >> i;
        vector<int> st;
        for (int i = n - 1; i + 1; i--) {
            st.pb(a[i]);
            while (st.size() > 1 && st[st.size()-2] == a[i]+1) st.pop_back(), st.back() = a[i];
        }
        
        cout << st.size() << "\n";
    }
}