#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s == string(s.rbegin(), s.rend())) cout << "yes";
    else cout << "no";
}