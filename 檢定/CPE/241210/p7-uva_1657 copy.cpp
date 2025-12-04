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
    int n, m; 
    while (cin >> n >> m) {
        vector<vector<int>> v(n+1, vector<int>(n+1));
        vector<int> add(410), mul(40010);
        for (int i = 1; i+1 <= n; i++) for (int j = i+1; j <= n; j++) add[i+j]++, mul[i*j]++;
        vector<PII> ans;
        for (int k = 0; k < m; k++) for (int i = 1; i+1 <= n; i++) for (int j = i+1; j <= n; j++) if (!v[i][j]) 
            if ((!(k&1) && add[i+j] == k) || (k&1 && mul[i*j] == k)) v[i][j] = 1;
        for (int i = 1; i+1 <= n; i++) for (int j = i+1; j <= n; j++) if (!v[i][j]) 
            if ((!(m&1) && add[i+j] == m) || (m&1 && mul[i*j] == m)) ans.pb({i, j});
        
        
        //for (int i = 1; i+1 <= n; i++) for (int j = i+1; j <= n; j++) if (!v[i][j] && ((!(m&1) && add[i+j] == 1) || (m&1 && mul[i*j] == 1))) ans.pb({i, j});
        
        cout << ans.size() << '\n';
        for (auto &i : ans) cout << i.fi << ' ' << i.se << '\n';
    }
}