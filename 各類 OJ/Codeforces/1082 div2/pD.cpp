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

void solve() {
    int n, k; cin >> n >> k;
    if (k < n || k > 2*n-1) return void(cout << "NO\n");
    cout << "YES\n";
    
    int p = k-n, m = p+1;
    vector<int> ans;
    
    if (!p) for (int i = 1; i <= n; i++) ans.pb(i), ans.pb(i);
    else {
        ans.pb(1), ans.pb(2);
        for (int i = 2; i < m; i++) ans.pb(i+1), ans.pb(i-1);
        ans.pb(m-1), ans.pb(m);
        for (int i = m+1; i <= n; i++) ans.pb(i), ans.pb(i);
    }
    
    for (auto &i : ans) cout << i << " \n"[&i == &ans.back()];
}

signed main() { WA();
    int t; for (cin >> t; t--;) solve();
}