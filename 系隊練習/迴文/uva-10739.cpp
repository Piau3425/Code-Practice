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
    int t = 1, T; for (cin >> T; t <= T; t++) {
        string s; cin >> s; int n = s.size();
        vector<vector<int>> v(n, vector<int>(n));
        for (int i = n-1; i >= 0; i--) {
            for (int j = i+1; j < n; j++) {
                if (s[i] == s[j]) v[i][j] = v[i+1][j-1];
                else v[i][j] = min({v[i+1][j-1], v[i+1][j], v[i][j-1]}) + 1;
            }
        }
        cout << "Case " << t << ": " << v[0][n-1] << '\n';
    }
}