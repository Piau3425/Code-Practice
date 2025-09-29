#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    string a, b; cin >> a >> b;
    vector<vector<int>> v(a.size()+1, vector<int>(b.size()+1));
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i-1] == b[j-1]) v[i][j] = v[i-1][j-1] + 1;
            else v[i][j] = max(v[i][j-1], v[i-1][j]);
        }
    }
    cout << v[a.size()][b.size()];
}