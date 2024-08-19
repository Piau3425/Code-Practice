#include <iostream>
using namespace std;

int main() {
    int c[10] = {}, t, mx = -1e9;
    for (int i = 0; i < 3; i++) {
        cin >> t;
        c[t]++;
        mx = max(mx, c[t]);
    }

    cout << mx << ' ';
    for (int i = 9; i >= 1; i--) if (c[i]) cout << i << ' ';
}