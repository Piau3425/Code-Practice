#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t; for (cin >> t; t--;) {
        int a, b, m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; cin >> a >> b;
        for (int i = 1; i < a; i++) b += m[i];
        string k[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        cout << k[(b+4)%7] << '\n';
    }
}