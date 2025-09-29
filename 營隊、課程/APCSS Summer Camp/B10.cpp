#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, mx = -1e9, my = -1e9, nx = 1e9, ny = 1e9;
    for (int i = 0; i < 4; i++) {
        cin >> x >> y;
        mx = max(mx, x);
        my = max(my, y);
        nx = min(nx, x);
        ny = min(ny, y);
    }
    cin >> x >> y;
    if (x >= nx && x <= mx && y >= ny && y <= my) cout << "IN";
    else cout << "OUT";
}