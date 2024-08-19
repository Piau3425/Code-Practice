#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d = 0, x = 0, y = 0, l = 0, r = 0, lr = 0, a[3];
    while (n--) {
        int nx, ny, nd;
        cin >> nx >> ny;
        if (nx - x > 0) nd = 0;
        if (nx - x < 0) nd = 3;
        if (ny - y > 0) nd = 2;
        if (ny - y < 0) nd = 1;
        a[(nd-d)%3]++;
    }
    
    for (auto i : a) cout << i << ' ';
}