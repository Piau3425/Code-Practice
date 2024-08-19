#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "AAAAA AAAAA A AAAA AAAAA AAAA", ans = "HELLO APCSS X APCS GUIDE CAMP";
    cout << str << '\n';
    for (int i = 0; i < str.size(); i++) {
        while (str[i] != ans[i]) {
            str[i] += 1;
            cout << str << '\n';
        }
    }
}