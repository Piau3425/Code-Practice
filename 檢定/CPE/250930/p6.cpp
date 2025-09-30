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
    int n, x;
    string s;
    getline(cin, s);
    while (getline(cin, s)) {
        vector<int> a;
        stringstream ss(s);
        while (ss >> x) a.pb(x);
        n = a.size();
        while (getline(cin, s) && s.size() > 2) {
            vector<int> b;
            ss.clear(); ss.str(s);
            while (ss >> x) b.pb(x);
            vector<int> dp(n, 1), c(n);
            for (int i = 0; i < n; i++) c[a[i]-1] = b[i];
            for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++)
                if (c[i] < c[j]) dp[j] = max(dp[j], dp[i]+1);
            cout << *max_element(all(dp)) << '\n';
        }
    }
}