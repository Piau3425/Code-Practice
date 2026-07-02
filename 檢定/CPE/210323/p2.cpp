#include <bits/stdc++.h>
using namespace std;

signed main() {
    for (string s; cin >> s;) {
        int a, b; a = b = 0;
        for (auto &c : s) {
            if (isalpha(c)) cout << "22233344455566677778889999"[c-'A'], a++;
            else cout << c, b++;
        }
        cout << '\n';
    }
}