#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t; cin.ignore();
    while (t--) {
        cin.ignore();
        string s; getline(cin, s);
        int n = s.size();
        vector<int> p(n);
        for (int i = 1; i < n; i++) {
            int j = p[i-1];
            while (j > 0 && s[i] != s[j]) j = p[j-1];
            p[i] = j + (s[i] == s[j]);
        }
        if (!(n%(n-p[n-1]))) cout << n-p[n-1] << '\n';
        else cout << n << '\n';
        if (t) cout << '\n';
    }
}