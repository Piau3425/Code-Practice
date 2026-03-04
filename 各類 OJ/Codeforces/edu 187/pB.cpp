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
        string s; cin >> s;
        int sum = 0, ans = 0; vector<int> v;

        for (auto &c : s) sum += c - '0', v.pb(c - (&c == &s.front() ? '1' : '0'));
        
        sort(all(v), greater<int>());

        for (auto i : v) if (sum > 9) sum -= i, ans++;
        
        cout << ans << "\n";
    }
}