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
    string s;
    while (getline(cin, s) && s != ".") {
        int n = s.size(), cnt = 0;
        vector<int> p(n);
        for (int i = 1; i < n; i++) {
            int j = p[i-1];
            while (j > 0 && s[i] != s[j]) j = p[j-1];
            p[i] = j + (s[i] == s[j]);
        }
        if (!(n%(n-p[n-1]))) cout << n/(n-p[n-1]) << '\n';
        else cout << "1\n";
    }
}