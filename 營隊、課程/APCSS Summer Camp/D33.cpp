#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void f(int len, int l, int r) {
    if (l > len || r > l) return;
    if (l == len && r == len) {ans++; return;}
    f(len, l+1, r);
    f(len, l, r+1);
}

int main() {
    int n;
    cin >> n;
    f(n, 0, 0);
    cout << ans;
}