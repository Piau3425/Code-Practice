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
    for (string s; cin >> s;) {
        int n = s.size();
        vector<vector<int>> v(n, vector<int>(n));
        for (int i = n-1; i >= 0; i--) {
            for (int j = i+1; j < n; j++) {
                if (s[i] == s[j]) v[i][j] = v[i+1][j-1];
                else v[i][j] = min({v[i+1][j], v[i][j-1]}) + 1;
            }
        }
        
        string l, r;
        for (int i = 0, j = n-1; i <= j;) {
            if (i == j) {
                l += s[i];
                break;
            }

            if (s[i] == s[j]) {
                l += s[i];
                r = s[i] + r;
                i++, j--;
            }
            else if (v[i][j] == v[i+1][j] + 1) {
                l += s[i];
                r = s[i] + r;
                i++;
            }
            else {
                l += s[j];
                r = s[j] + r;
                j--;
            }
        }
        cout << v[0][n-1] << ' ' << l+r << '\n';
    }
}