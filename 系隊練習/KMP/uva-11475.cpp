#include <bits/stdc++.h>
using namespace std;

#define WA() cin.tie(0)->sync_with_stdio(0)

signed main() { WA();
    string s;
    while (cin >> s) {
        string r(s.rbegin(), s.rend()), t = r + "#" + s;
        int n = t.size();
        vector<int> p(n);
        for (int i = 1; i < n; i++) {
            int j = p[i-1];
            while (j > 0 && t[i] != t[j]) j = p[j-1];
            p[i] = j + (t[i] == t[j]);
        }

        cout << s << r.substr(p.back()) << '\n';
    }
}