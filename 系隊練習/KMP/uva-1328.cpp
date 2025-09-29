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
    int n, T = 0; while (cin >> n, n) {
        cout << "Test case #" << ++T << '\n';
        string s; cin >> s;
        vector<int> p(n);
        for (int i = 1; i < n; i++) {
            int j = p[i-1];
            while (j > 0 && s[i] != s[j]) j = p[j-1];
            p[i] = j + (s[i] == s[j]);
        }
        
        for (int i = 1; i < n; i++) {
            int len = i+1 - p[i];
            if (!((i+1)%len) && (i+1)/len > 1) cout << i+1 << ' ' << (i+1)/len << '\n';
        }
        cout << '\n';
    }
}