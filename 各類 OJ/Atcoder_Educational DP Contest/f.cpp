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

signed main() { //WA();
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size(), i, j;
    vector<vector<int>> v(n+1, vector<int>(m+1));
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) v[i][j] = v[i-1][j-1]+1;
            else v[i][j] = max(v[i-1][j], v[i][j-1]);
        }
    }
    //cout << i << ' ' << j << '\n';
    string ans; i--, j--;
    while (i && j) {
        if (a[i-1] == b[j-1]) ans += a[i-1], i--, j--;
        else if (v[i][j] == v[i][j-1]) j--;
        else i--;
    }
    cout << string(ans.rbegin(), ans.rend());
}