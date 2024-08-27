#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d = 0, x = 0, y = 0, l = 0, r = 0, lr = 0;
    cin >> n;
    while (n--) {
        int nx, ny, nd;
        cin >> nx >> ny;
        if (nx > x) nd = 0;
        if (ny < y) nd = 1;
        if (nx < x) nd = 2;
        if (ny > y) nd = 3;
        
        
        if (nd == (d+1)%4) r++;
        else if (nd == (d+2)%4) lr++;
        else if (nd == (d+3)%4) l++;
        
        x = nx; y = ny; d = nd;
    }
    
    cout << l << ' ' << r << ' ' << lr;
}