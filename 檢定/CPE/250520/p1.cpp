#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, T = 0;
    while (cin >> n) {
        vector<int> v(n);
        set<int> st;
        for (auto &i : v) cin >> i;
        int flag = v[0] <= 0;
        for (int i = 0; i+1 < n; i++) if (v[i] >= v[i+1]) flag = 1;
        for (int i = 0; i < n; i++) for (int j = i; j < n; j++) {
            if (st.count(v[i]+v[j])) flag = 1;
            st.insert(v[i]+v[j]);
        }
        cout << "Case #" << ++T << ": It is" << (flag ? " not " : " ") << "a B2-Sequence.\n\n";
    }
}