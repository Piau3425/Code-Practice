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
    int n, k; string s;
    getline(cin, s);
    while (getline(cin, s)) {
        vector<int> a, b;
        stringstream ss(s);
        while (ss >> k) a.pb(k);
        n = a.size();
        while (getline(cin, s) && s.size() > 2) {
            b.clear();
            stringstream sss(s);
            vector<int> dp, c(n);
            while (sss >> k) b.pb(k);
            for (int i = 0; i < n; i++) c[a[i]-1] = b[i];
            for (auto &i : c) {
                if (dp.empty() || i > dp.back()) dp.pb(i);
                else *lower_bound(all(dp), i) = i;
            }
            cout << dp.size() << '\n';
        }
    }
}