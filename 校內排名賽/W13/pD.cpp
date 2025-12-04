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
    int t; for (cin >> t, cin.ignore(); t--;) {
        string s, rs; getline(cin , s);
        rs = string(s.rbegin(), s.rend());
        int n = s.size();
        vector<vector<int>> v(n+1, vector<int>(n+1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == rs[j-1]) v[i][j] = v[i-1][j-1]+1;
                else v[i][j] = max(v[i-1][j], v[i][j-1]);
            }
        }
        cout << v[n][n] << '\n';
    }
}