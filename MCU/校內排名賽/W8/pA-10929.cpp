#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (cin >> s, s != "0") {
        int sum = 0;
        for (auto c : s) sum = (sum*10+c-'0')%11;
        cout << s << " is" << (sum ? " not " : " ") << "a multiple of 11.\n";
    }
}