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
    int t; cin >> t; cin.ignore(); cin.ignore();
    while (t--) {
        string sn;
        vector<int> a, b;
        while (getline(cin, sn), sn != "") a.pb(stoi(sn));
        int n = a.size();
        b = a; sort(all(b));
        vector<vector<int>> v(n+1, vector<int>(n+1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i-1] == b[j-1]) v[i][j] = v[i-1][j-1] + 1;
                else v[i][j] = max(v[i-1][j], v[i][j-1]);
            }
        }
        int i, j; i = j = n;
        set<int> ans;
        while (i && j) {
            if (a[i-1] == b[j-1]) ans.insert(a[i-1]), i--, j--;
            else if (v[i][j-1] == v[i][j]) j--;
            else i--;
        }
        cout << "Max hits: " << ans.size() << '\n';
        for (auto &i : ans) cout << i << '\n';
        if (t) cout << '\n';
    }
}