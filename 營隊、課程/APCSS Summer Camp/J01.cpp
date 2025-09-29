#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int len = 1, ans = -1e9;
    cin >> s;
    for (int i = 0; i+1 < s.size(); i++) {
        len += s[i] == s[i+1];
        if (s[i] != s[i+1]) {
            ans = max(len, ans);
            len = 1;
        }
    }
    ans = max(len, ans);

    cout << ans;
}