#include <bits/stdc++.h>
using namespace std;
#define WA() cin.tie(0)->sync_with_stdio(0)

signed main() {
    string s;
    while (cin >> s) {
        set<string> st;
        for (int i = 3; i <= min(4, (int)s.size()); i ++) {
            for (int j = 0; j < s.size()-i+1; j++) {
                string sub = s.substr(j, i);
                if (string(sub.rbegin(), sub.rend()) == sub) st.insert(sub);
            }
        }
        int cnt = 0;
        if (st.size() >= 2) {
            for (auto i : st) {
                int ck = 1;
                for (auto j : st) if (i != j && i.find(j) != string::npos) ck = 0;
                cnt += ck;
            }
        }
        if (cnt >= 2) printf("%s\n", s.data());
    }
}