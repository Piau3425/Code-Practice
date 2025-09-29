#include <bits/stdc++.h>
using namespace std;

int f(int a, int b) {
    if (b == 1 || a == b) return 1;
    return f(a-1, b) + f(a-1, b-1);
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << f(x, y);
}