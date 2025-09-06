#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m, cout << n << ' ' << m << endl, n+m) {
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        sort(v.begin(), v.end(), [m](int a, int b) -> bool {
            if (a%m != b%m) return a%m < b%m;
            if (a&1 && b&1) return a > b;
            if (!(a&1) && !(b&1)) return a < b;
            return a&1;
        });
        for (auto i : v) cout << i << endl;
    }
}