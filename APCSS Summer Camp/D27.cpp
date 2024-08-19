#include <bits/stdc++.h>
using namespace std;

int f(int x) {
    if (x == 1) return 1;
    if (!(x&1)) return f(x/2);
    return f(x-1) + f(x+1);
}

int main() {
    int x;
    cin >> x;
    cout << f(x);
}