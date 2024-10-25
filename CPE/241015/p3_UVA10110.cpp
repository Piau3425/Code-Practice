#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    while (cin >> n && n) {
        if (sqrt(n) == (int)sqrt(n)) cout << "yes\n";
        else cout << "no\n";
    }
}