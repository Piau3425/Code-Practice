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
    int t; cin >> t;
    while (t--) {
        string s, k; cin >> s >> k;
        string m = s + "#" + k;
        int n = m.size();
        vector<int> p(n);
        for (int i = 1; i < n; i++) {
            int j = p[i-1];
            while (j > 0 && m[i] != m[j]) j = p[j-1];
            p[i] = j + (m[i] == m[j]);
        }
        int cnt = 0;
        for (auto &i : p) if (i == s.size()) cnt++;
        cout << cnt << '\n';
    }
}