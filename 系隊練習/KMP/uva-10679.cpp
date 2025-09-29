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
    int k; cin >> k;
    while (k--) {
        string t, pa; cin >> t;
        int q; cin >> q;
        while (q--) {
            cin >> pa;
            string m = pa + "#" + t;
            int n = m.size();
            vector<int> p(n);
            for (int i = 1; i < n; i++) {
                int j = p[i-1];
                while (j > 0 && m[i] != m[j]) j = p[j-1];
                p[i] = j + (m[i] == m[j]);
            }
            int i;
            for (i = pa.size()+1; i < n; i++) if (p[i] == pa.size()) break;
            if (i == n) cout << "n\n";
            else cout << "y\n";
        }
    }
}