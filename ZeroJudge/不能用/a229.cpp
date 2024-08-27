#include <bits/stdc++.h>
using namespace std;

void f(int len, vector<char> &hs, int l, int r) {
    if (l > len || r > l) return;
    if (l == len && r == len) {for (auto c : hs) cout << c; cout << "\n\n"; return;}
    hs.push_back('(');
    f(len, hs, l+1, r);
    hs.pop_back();
    hs.push_back(')');
    f(len, hs, l, r+1);
    hs.pop_back();
}

int main() {
    int n;
    cin >> n;
    vector<char> v;
    f(n, v, 0, 0);
}